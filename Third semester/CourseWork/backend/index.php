<?php
require 'source/database/methods.php';

//$GLOBALS['config'] = json_decode(readfile('config.json'));

if (isset($_GET['method'])){
    $methods = new \database\Methods();
    switch ($_GET['method']){
        case 'getInstitutesList':
            echo $methods->getInstitutesList();
            break;
        case 'getGroupsByInstitute':
            if (isset($_GET['institute_id'])){
                echo $methods->getGroupByInstitute($_GET['institute_id']);
                break;
            }
            die('Invalid institute_id');
        case 'getStudentsByGroup':
            if (isset($_GET['group_id'])){
                echo $methods->getStudentsByGroup($_GET['group_id']);
                break;
            }
            die('Invalid group_id');
        default:
            die('Invalid method');
    }
}
else
    die('Invalid request');