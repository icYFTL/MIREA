<?php


namespace database;
use SQLite3;

class Methods
{
    private $conn = null;
    public function __construct(){
        $this->conn = new SQLite3("px.db") or die('database down');
        $this->initDb();
    }

    private function initDb(){
        $this->conn->exec('CREATE TABLE IF NOT EXISTS institutes (id INTEGER PRIMARY KEY, name TEXT unique);');
        $this->conn->exec('CREATE TABLE IF NOT EXISTS groups     (id INTEGER PRIMARY KEY, name TEXT unique, i_id INTEGER, FOREIGN KEY (i_id) REFERENCES institutes(id));');
        $this->conn->exec('CREATE TABLE IF NOT EXISTS students   (id INTEGER PRIMARY KEY, surname TEXT NOT NULL DEFAULT "", name TEXT NOT NULL DEFAULT "", patronymic TEXT NOT NULL DEFAULT "", username TEXT DEFAULT NULL, password TEXT, group_id INTEGER, FOREIGN KEY (group_id) REFERENCES groups(id));');
    }

    public function getInstitutesList(){
        $result = $this->conn->query("SELECT * FROM institutes;") or die('Something went wrong');
        $tmp = array();
        while ($_ = $result->fetchArray(SQLITE3_ASSOC) )
            array_push($tmp, $_);
        return json_encode($tmp, JSON_UNESCAPED_UNICODE);
    }

    public function getGroupByInstitute($institute_id){
        if (intval($institute_id) === 0)
            die('Invalid value passed');
        $result = $this->conn->query("SELECT * FROM groups WHERE i_id={$institute_id};") or die('Something went wrong');
        $tmp = array();
        while ($_ = $result->fetchArray(SQLITE3_ASSOC) )
            array_push($tmp, $_);
        return json_encode($tmp, JSON_UNESCAPED_UNICODE);
    }

    public function getStudentsByGroup($group_id){
        if (intval($group_id) === 0)
            die('Invalid value passed');
        $result = $this->conn->query("SELECT id, name,surname,patronymic FROM students WHERE group_id={$group_id};") or die('Something went wrong');
        $tmp = array();
        while ($_ = $result->fetchArray(SQLITE3_ASSOC) )
            array_push($tmp, $_);
        return json_encode($tmp, JSON_UNESCAPED_UNICODE);
    }
}