/*
 * NOTICE: THIS SOLUTION PROBABLY WILL NOT WORK CORRECTLY
 * NOTICE: U NEED TO DOWNLOAD AND CONNECT BOOST LIBRARY TO THE PROJECT (GOOGLE IT)
 * */

#define _WIN32_WINNT 0x0A00
#define BOOST_DATE_TIME_NO_LIB
#define BOOST_REGEX_NO_LIB

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/format.hpp>
#include <sstream>
#include <regex>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <cstdlib>



using namespace std;
using boost::asio::ip::tcp;

double m, S, n;
string host = "api.wolframalpha.com";
string url = url = "/v2/query?input=m+%3D+%28S+*+p%2F100+*+pow%28%281+%2B+p%2F100%29%2C+n%29%29+%2F+%2812+*+%28%28pow%28%281+%2B+p%2F100%29%2C+n%29+-+1%29%29%29+for+m+%3D+" + to_string(m) + "%2C+S+%3D+" + to_string(S) + "%2C+n+%3D+" + to_string(n) + "&appid=" + this->app_id;
string app_id = "VKQG3T-QE5HK5QU2Y";

string request() {

    try
    {

        boost::asio::io_service io_service;


        tcp::resolver resolver(io_service);
        tcp::resolver::query query(this->host, "http");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);


        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);




        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << "GET " << this->url << " HTTP/1.0\r\n";
        request_stream << "Host: " << this->host << "\r\n";
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: close\r\n\r\n";


        boost::asio::write(socket, request);




        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");


        std::istream response_stream(&response);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);
        if (!response_stream || http_version.substr(0, 5) != "HTTP/")
        {
            std::cout << "Invalid response\n";
            return "None";
        }
        if (status_code != 200)
        {
            std::cout << "Response returned with status code " << status_code << "\n";
            return "None";
        }


        boost::asio::read_until(socket, response, "\r\n\r\n");


        std::string header;
        //while (std::getline(response_stream, header) && header != "\r")
        //std::cout << header << "\n";
        //std::cout << "\n";
        stringstream answer;


        if (response.size() > 0)
            answer << &response;


        boost::system::error_code error;

        while (boost::asio::read(socket, response,
                                 boost::asio::transfer_at_least(1), error))
            answer << &response;


        return answer.str();

        if (error != boost::asio::error::eof)
            throw boost::system::system_error(error);

    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return "None";
}

void write_it(string ans) {
	ofstream fout("ans.txt");
	fout << ans;
	fout.close();
}

string get_p(string data) {
	string out = "";
	smatch m;
	regex e("alt='p[ ]?\\D+[ ]?[0-9.]+'");
	if (regex_search(data, m, e)) {
		for (string ans : m) {
			out += ans;
			break;
		}

	}
	vector<string> details;
	boost::split(details, out, boost::is_any_of(" "));
	if (details[2].find("...'") != string::npos)
		out = regex_replace(details[2], regex("...'"), "");
	else
		out = regex_replace(details[2], regex("'"), "");


	return out;
}

class InputData {
private:
	string filename = "request.txt";
public:
	bool file_exists() {
		ifstream fin(this->filename);
		return fin.good();
	}

	vector<int> get_data() {
		ifstream fin(this->filename);
		string str;
		vector<int> out;
		while (fin >> str)
			out.push_back(stoi(str));

		return out;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	int m, S, n;
	InputData ID;


	if (ID.file_exists()) {
		vector<int> data = ID.get_data();
		S = data[0];
		m = data[1];
		n = data[2];
	}
	else {
		cout << "Give me the values: " << endl << "S: " << endl << "> ";
		cin >> S;
		cout << endl << "m: " << endl << "> ";
		cin >> m;
		cout << endl << "n: " << endl << "> ";
		cin >> n;
		cout << endl;
	}
	string data = get_p(request());

	cout << endl << "ANSWER: " << endl << data;
	write_it(data);



}
