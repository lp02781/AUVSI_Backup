#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <ctype.h>
#include <iomanip>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/reader.h"

using namespace std;

//#############################################################################################  MAIN VARIABLE  ###############
string	challenge_status	= "idle";
string 	server_ip			= "10.0.2.2";
int 	server_port			= 80;
string 	team_code			= "AMVUI";
string	course_type 		= "courseUI"; //courseA courseB courseC courseUI

#define STEERING 0
#define THROTTLE 2
#define SIMPLE_PIN 3
#define CAMERA_SERVO 4

#define MAX_THROTTLE 1900//1750
#define MIN_THROTTLE 1100
#define MAX_STEERING 1900
#define MIN_STEERING 1100

#define PWM_UP 	1700
#define PWM_LOW 1300
#define MIDDLE_PWM 	1520

#define CAM_INIT_PWM 1500

string mission_idle = "no_mission";

float update_time=0.01;
float delta_t = 0.01;
float initial_time = 0; 

int number_camera=0;

int zero_flag 		= 0;
int first_simple 	= 1;
int second_simple 	= 2;

//###############################################################################################  NAVIGATION VARIABLE  ###############
#define THROT_NAV 1650

float longitude_nav_end_A=1551;
float latitude_nav_end_A=12515;

float longitude_nav_end_B=1161;
float latitude_nav_end_B=3161613;

float longitude_nav_end_C=21515;
float latitude_nav_end_C=136136;

float longitude_nav_end_UI=13613631;
float latitude_nav_end_UI=3161361;

float tolerance_nav=12516;
float kp_nav = 1.65;//1.5
float ki_nav = 1;//1
float kd_nav = 0.5;//0.5
int setpoint_nav=160;
int x_nav=0;
int y_nav=180;
int width_nav=280; //width 400 for simple
int height_nav=180;
int LowH_nav	= 0; 		//0  
int HighH_nav 	= 184;		//184 
int LowS_nav 	= 130;      //130  65
int HighS_nav 	= 248;      //248  246
int LowV_nav 	= 49;		//49   242
int HighV_nav 	= 230;		//230  255
int Noise_nav 	= 15;

//####################################################################################	SPEEED VARIABLE  ###############
#define THROT_SPEED 1650

float longitude_speed_end_A=0;
float latitude_speed_end_A=0;

float longitude_speed_end_B=0;
float latitude_speed_end_B=0;

float longitude_speed_end_C=0;
float latitude_speed_end_C=0;

float longitude_speed_end_UI=0;
float latitude_speed_end_UI=0;

float tolerance_speed=0;

double compass_point=60;
double compass_tolerance = 5;

//blue buoy
float kp_speed= 1.65;//1.5
float ki_speed = 1;//1
float kd_speed = 0.5;//0.5
int setpoint_speed=50;
int x_speed=0;
int y_speed=180;
int width_speed	=280; //width 400 for simple
int height_speed=180;
int LowH_speed	= 0; 		//0  
int HighH_speed = 184;		//184 
int LowS_speed 	= 130;      //130  65
int HighS_speed = 248;      //248  246
int LowV_speed 	= 49;		//49   242
int HighV_speed = 230;		//230  255
int Noise_speed = 15;

//red buoy
float kp_speed_new= 1.65;//1.5
float ki_speed_new = 1;//1
float kd_speed_new = 0.5;//0.5
int setpoint_speed_new=160;
int x_speed_new=0;
int y_speed_new=180;
int width_speed_new	=280; //width 400 for simple
int height_speed_new=180;
int LowH_speed_new	= 0; 		//0  
int HighH_speed_new = 184;		//184 
int LowS_speed_new 	= 130;      //130  65
int HighS_speed_new = 248;      //248  246
int LowV_speed_new 	= 49;		//49   242
int HighV_speed_new = 230;		//230  255
int Noise_speed_new = 15;

//#################################################################################################	PATH	##############################################
#define THROT_PATH 1650

//################################################################################################  FOLLOW  ###############
#define THROT_FOLLOW 1650
#define CAM_FOLLOW_PWM 1700

double compass_point_follow=300;

float longitude_follow_end_A=0;
float latitude_follow_end_A=0;

float longitude_follow_end_B=0;
float latitude_follow_end_B=0;

float longitude_follow_end_C=0;
float latitude_follow_end_C=0;

float longitude_follow_end_UI=0;
float latitude_follow_end_UI=0;

float tolerance_follow=0;

float kp_follow_x = 1.65;//1.5
float ki_follow_x = 1;//1
float kd_follow_x = 0.5;//0.5
int setpoint_follow_x=160;

float kp_follow_y = 1.65;//1.5
float ki_follow_y = 1;//1
float kd_follow_y = 0.5;//0.5
int setpoint_follow_y=160;

int x_follow=0;
int y_follow=180;

int width_follow=280; //width 400 for simple
int height_follow=180;

int LowH_follow		= 0; 		//0  
int HighH_follow 	= 184;		//184 
int LowS_follow 	= 130;      //130  65
int HighS_follow 	= 248;      //248  246
int LowV_follow 	= 49;		//49   242
int HighV_follow 	= 230;		//230  255
int Noise_follow 	= 15;


//################################################################################################  FLAG  ###############
#define THROT_FLAG 1650
#define CAM_FLAG_PWM 1700

int x_flag_crash = 1;
int x_docking_crash = 1;

//################################################################################################  DRONE  #################
int alt_threshold = 1;
float kp_drone = 1.65;//1.5
float ki_drone = 1;//1
float kd_drone = 0.5;//0.5
int setpoint_drone=160;
int x_drone=0;
int y_drone=180;
int width_drone=280; //width 400 for simple
int height_drone=180;
int LowH_drone	= 0; 		//0  
int HighH_drone 	= 184;		//184 
int LowS_drone 	= 130;      //130  65
int HighS_drone 	= 248;      //248  246
int LowV_drone 	= 49;		//49   242
int HighV_drone 	= 230;		//230  255
int Noise_drone 	= 15;

float kp_drone_x = 1.65;//1.5
float ki_drone_x = 1;//1
float kd_drone_x = 0.5;//0.5
int setpoint_drone_x=160;

float kp_drone_y = 1.65;//1.5
float ki_drone_y = 1;//1
float kd_drone_y = 0.5;//0.5
int setpoint_drone_y=160;

//############################################################################################# COMMUNICATION ####################################################
using namespace rapidjson;

enum communicationType {navigation, speed, docking, path, follow, flag, return_dock, start_run, end_run};

// ######################################################################################## JSONHandler struct ########################################## //
struct JSONHandler {
	vector<string> json_element;
	void clearJSONVector(){this->json_element.clear();}
	bool Null() {return true; }
	bool Bool(bool b) {
		if(b)this->json_element.push_back("true");
		else this->json_element.push_back("false");
		return true; 
	}
    bool Int(int i) {return true; }
    bool Uint(unsigned u) {return true; }
    bool Int64(int64_t i) {return true; }
    bool Uint64(uint64_t u) {return true; }
    bool Double(double d) {return true; }
    bool RawNumber(const char* str, SizeType length, bool copy) {return true;}
    bool String(const char* str, SizeType length, bool copy) {
		string buffer_string;
		buffer_string.append(str);
		this->json_element.push_back(buffer_string);
		return true;
    }
    bool StartObject() {return true; }
    bool Key(const char* str, SizeType length, bool copy) {
		string buffer_string;
		buffer_string.append(str);
		this->json_element.push_back(buffer_string);
		return true;
    }
    bool EndObject(SizeType memberCount) {return true; }
    bool StartArray() {return true; }
    bool EndArray(SizeType elementCount) {return true; }
};
 // ####################################################################################### AUVSICommunication class ########################################## //
class AUVSICommunication {

	protected:
		string payload;
		string response_message = "No data";
		string hostname;
		int port_number;
		string course_type;
		string team_code;
		int receive_timeout = 10;

	public:
		JSONHandler json_handler;
		AUVSICommunication                    (string hostname_input, int port_number_input, string course_type, string team_code);
		int sendTCP                           ();
		string getPayload                     ();
		string getResponse                    ();
		bool setRemoteTarget                  (string hostname_input, int port_number_input);
		bool setPayload                       (string input_data);
		void setReceiveTimeout                (int receive_timeout);
		void setCourseType                    (string course_type);
		void setTeamCode                      (string team_code);
		int decodeResponeStatus               ();
		int decodedResponse                   ();
		int decodedResponse                   (string response_message);
		int decodeJSON                        (string parsed_http_response);
};

AUVSICommunication::AUVSICommunication(string hostname, int port_number, string course_type, string team_code){
    this->hostname = hostname;
    this->port_number = port_number;
    this->payload = "No data";
    this->course_type = course_type;
    this->team_code = team_code;
}

bool AUVSICommunication::setRemoteTarget(string hostname_input, int port_number_input){
    hostname = hostname_input;
    port_number = port_number_input;
}

bool AUVSICommunication::setPayload (string input_data){
    payload = input_data;
}

int AUVSICommunication::sendTCP(){
	// ################## create socket ################## //
    int socket_desc;
    struct sockaddr_in server;
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
		//cout << "Could not create socket";
		response_message = "No data";
		return -1;
    }
    server.sin_addr.s_addr = inet_addr(hostname.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons( port_number );
    // ################## create socket ################## //

    // ################## connect to remote server ################## //
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
		//cout << "connect error\n";
		response_message = "No data";
		return -1;
    }

    //cout << "Connected\n";
    // ################## connect to remote server ################## //

    // ################## Send some data ################## //
    //cout << "Message size " << payload.size() << endl;
    if( send(socket_desc , payload.c_str() , payload.size(), 0) < 0){
		//cout << "Send failed";
		response_message = "No data";
		return -1;
    }
    //cout << "Data Send\n";
    // ################## Send some data ################## //

    // ################## Receive some data ################## //
    // ################## set receive timout ################## //
    struct timeval tv;
    tv.tv_sec 	= receive_timeout;  /* 30 Secs Timeout */
    tv.tv_usec 	= 0;  // Not init'ing this can cause strange errors
    setsockopt(socket_desc, SOL_SOCKET, SO_RCVTIMEO, &tv,sizeof(tv));
    errno = 0;	// reset errno
    // ################## set receive timout ################## //

    // create the buffer with space for the data
    const unsigned int MAX_BUF_LENGTH = 4096;
    std::vector<char> buffer(MAX_BUF_LENGTH);
    std::string rcv;
    int bytesReceived = 0;
    do {
		bytesReceived = recv(socket_desc, buffer.data(), buffer.size(), 0);
		// append string from buffer.
		if ( bytesReceived == -1 ) {
			//cout << "recv failed
			response_message = "No data";
			return -1;

		} 
		else {
			rcv.append( buffer.cbegin(), buffer.cend() );
		}
    } 
    while ( bytesReceived == MAX_BUF_LENGTH );

    if (errno == EAGAIN){
		response_message = "No data";
		return -1;
    }

    //cout << "Reply received\n";
    // ################## Receive some data ################## //

    // ################## Convert to string ################## //
    std::stringstream ss;
    for(size_t i = 0; i < buffer.size(); ++i){
		ss << buffer[i];
    }
    // ################## Convert to string ################## //

    close(socket_desc);

    response_message = ss.str();
    return 1;
}

string AUVSICommunication::getPayload (){
    return payload;
}

string AUVSICommunication::getResponse(){
	return response_message;
}

void AUVSICommunication::setReceiveTimeout(int receive_timeout){
    this->receive_timeout = receive_timeout;
}

void AUVSICommunication::setTeamCode(string team_code){
    this->team_code = team_code;
}

void AUVSICommunication::setCourseType(string course_type){
    this->course_type = course_type;
}

int AUVSICommunication::decodeResponeStatus(){
    if (response_message.find("HTTP/1.1 200") != std::string::npos) {
		return 200;
    }
    else if (response_message.find("HTTP/1.1 400") != std::string::npos) {
		return 400;
    }
    else if (response_message.find("HTTP/1.1 404") != std::string::npos) {
		return 404;
    }
    else if (response_message.find("HTTP/1.1 500") != std::string::npos) {
		return 500;
    }
    else if (response_message.find("HTTP/1.1 503") != std::string::npos) {
		return 503;
    }
      else if (response_message.find("HTTP/1.1 100") != std::string::npos) {
		return 100;
    }
    else {
		return -1;
    }
}

int AUVSICommunication::decodeJSON(string parsed_http_response){
    Reader reader;
    StringStream ss(parsed_http_response.c_str());
    json_handler.clearJSONVector();
    reader.Parse(ss, json_handler);
    if (reader.HasParseError()) {
		return -1;
    }
    return 1;
}
 
int AUVSICommunication::decodedResponse(){
    return this->decodedResponse(this->response_message);
}
  
int AUVSICommunication::decodedResponse(string response_message){
    string parsed_http_response;
    try{
		std::size_t pos =   response_message.find("\r\n\r\n");      // position of "live" in str

		parsed_http_response =   response_message.substr (pos);     // get from "live" to the end
		parsed_http_response.erase(0, 4);
		parsed_http_response.erase(parsed_http_response.length()-2,2);
    }
    catch (exception x){
		return 0;
    }

    return this->decodeJSON(parsed_http_response);
}


  // ################################################################################# HEARTBEAT CLASS ########################################## //

class HeartbeatMessage : public AUVSICommunication {

	private:

		int gps_precision = 9;

	public:

		HeartbeatMessage(string hostname, int port_number, string course_type, string team_code);
		void setPayloadCommunication(string timestamp_mission, string challenge, float latitude, float longitude);
		void setGPSPrecision          (int gps_precision);
};

HeartbeatMessage::HeartbeatMessage(string hostname, int port_number, string course_type, string team_code)
  : AUVSICommunication(hostname, port_number, course_type, team_code){}


void HeartbeatMessage::setGPSPrecision(int gps_precision){
    this->gps_precision = gps_precision;
}

void HeartbeatMessage::setPayloadCommunication(string timestamp_mission, string challenge, float latitude, float longitude){
    string filename = "/heartbeat/" + course_type + "/";
    filename.append(team_code);
    string payload_stream;
    payload_stream.append("{\"timestamp\":\"" + timestamp_mission + "\",");
    payload_stream.append("\"challenge\":\"" + challenge + "\",");
    payload_stream.append("\"position\":{\"datum\":\"WGS84\",\"latitude\":");
    std::stringstream ss_lat;
    ss_lat << std::setprecision(gps_precision) << latitude;
    std::stringstream ss_long;
    ss_long << std::setprecision(gps_precision) << longitude;
    payload_stream.append(ss_lat.str() + ",\"longitude\":" + ss_long.str() + "}}");

    int payload_size = payload_stream.size();
    string http_request;
    http_request.append("POST "+ filename +" HTTP/1.1\r\n");
    http_request.append("Host: " + hostname + ":" + to_string(port_number) + "\r\n");
    http_request.append("Content-Length: "+ to_string(payload_size) + "\r\n");
    http_request.append("Content-Type: application/json\r\n\r\n");
    http_request.append(payload_stream);

    payload = http_request;
}

  // ######################################################################################## StartEndRunMessage class ########################################## //

class StartEndRunMessage : public AUVSICommunication {

	public:

		StartEndRunMessage(string hostname, int port_number, string course_type, string team_code);
		bool setPayloadCommunication(communicationType comm_type);
};


StartEndRunMessage::StartEndRunMessage(string hostname, int port_number, string course_type, string team_code)
	:AUVSICommunication(hostname, port_number, course_type, team_code){}

bool StartEndRunMessage::setPayloadCommunication(communicationType comm_type){
    if (comm_type == start_run || comm_type == end_run ){
		string course_description = "empty";

		if (comm_type == start_run){
			course_description = "start";
		} 
		else if (comm_type == end_run){
			course_description = "end";
		}

		string filename;
		string http_request;
		filename.append("/run/" + course_description + "/" + course_type + "/" + team_code);
		http_request.append("POST "+ filename +" HTTP/1.1\r\n");
		http_request.append("Host: " + hostname + ":" + to_string(port_number) + "\r\n");
		http_request.append("Content-Length: 0\r\n");
		http_request.append("Content-Type: application/json\r\n\r\n");

		payload = http_request;
		return true;
    }
    return false;
}
// ################################################################################### START MISSION CLASS ########################################## //
class MissionMessage : public AUVSICommunication {

	public:
		MissionMessage(string hostname, int port_number, string course_type, string team_code);
		bool setPayloadCommunication(communicationType comm_type);
};

MissionMessage::MissionMessage(string hostname, int port_number, string course_type, string team_code)
  : AUVSICommunication(hostname, port_number, course_type, team_code){}

bool MissionMessage::setPayloadCommunication(communicationType comm_type){

    if (comm_type == navigation || comm_type == speed || comm_type == docking || comm_type == path || comm_type == follow || comm_type == flag || comm_type == return_dock ){

      string course_description;

      if (comm_type == navigation){
			course_description = "navigation";
      } 
      else if (comm_type == speed){
			course_description = "speed";
      }
      else if (comm_type == docking){
			course_description = "docking";
      }
      else if (comm_type == path){
			course_description = "path";
      }
      else if (comm_type == follow){
			course_description = "followLeader";
      }
      else if (comm_type == flag){
			course_description = "flag";
      }
      else if (comm_type == return_dock){
			course_description = "return";
      }

      string filename;
      string http_request;
      filename.append("/" + course_description + "/" + course_type + "/" + team_code);
      http_request.append("GET "+ filename +" HTTP/1.1\r\n");
      http_request.append("Host: " + hostname + ":" + to_string(port_number) + "\r\n");
      http_request.append("Accept: */*\r\n\r\n");
      payload = http_request;
      return true;
   }
   return false;
}

// ################################################################################################ DockingMessage class ########################################## //
class DockingMission : public AUVSICommunication {

	public:
		DockingMission(string hostname, int port_number, string course_type, string team_code);
		bool setPayloadCommunication(communicationType comm_type);
};

DockingMission::DockingMission(string hostname, int port_number, string course_type, string team_code)
  : AUVSICommunication(hostname, port_number, course_type, team_code){}

bool DockingMission::setPayloadCommunication(communicationType comm_type){

    if (comm_type == navigation || comm_type == speed || comm_type == docking || comm_type == path || comm_type == follow || comm_type == flag || comm_type == return_dock ){

      string course_description;

      if (comm_type == navigation){
			course_description = "navigation";
      } 
      else if (comm_type == speed){
			course_description = "speed";
      }
      else if (comm_type == docking){
			course_description = "docking";
      }
      else if (comm_type == path){
			course_description = "path";
      }
      else if (comm_type == follow){
			course_description = "followLeader";
      }
      else if (comm_type == flag){
			course_description = "flag";
      }
      else if (comm_type == return_dock){
			course_description = "return";
      }

		string filename;
		string http_request;
		filename.append(course_description + "/image/" + course_type + "/" + team_code);
		http_request.append("POST "+ filename +" HTTP/1.1\r\n");
		http_request.append("Content-Type: multipart/form-data; boundary=PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV\r\n");
		http_request.append("Host: " + hostname + ":" + to_string(port_number) + "\r\n");
		http_request.append("Accept: */*\r\n");
		http_request.append("Content-Length: 7280\r\n");
		http_request.append("Expect: 100-continue\r\n\r\n");
	
		http_request.append("--PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV");
		http_request.append("Content-Disposition: form-data; name=docking; filename=../docking.jpg");
		http_request.append("Content-Type: application/octet-stream\r\n");
		http_request.append("c1790bde8f831e7c\r\n");
		http_request.append("--PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV\r\n\r\n");
		
		payload = http_request;
		return true;
   }
   return false;
   
	//> POST /docking/image/courseA/AUVSI HTTP/1.1
	//> Content-Type: multipart/form-data; boundary=PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV
	//> User-Agent: curl/7.38.0
	//> Host: 127.0.0.1:8080
	//> Accept: */*
	//> Content-Length: 7280
	//> Expect: 100-continue
	//>
	//< HTTP/1.1 100 Continue
	//> --PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV
	//> Content-Disposition: form-data; name="file"; filename="test.jpg"
	//> Content-Type: application/octet-stream
	//>
	//> c1790bde8f831e7c
	//> --PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV
	//>
	//< HTTP/1.1 202 Accepted
}

// ################################################################################################ FlagMessage class ########################################## //
class FlagMission : public AUVSICommunication {

	public:
		FlagMission(string hostname, int port_number, string course_type, string team_code);
		bool setPayloadCommunication(communicationType comm_type);
};

FlagMission::FlagMission(string hostname, int port_number, string course_type, string team_code)
  : AUVSICommunication(hostname, port_number, course_type, team_code){}

bool FlagMission::setPayloadCommunication(communicationType comm_type){

    if (comm_type == navigation || comm_type == speed || comm_type == docking || comm_type == path || comm_type == follow || comm_type == flag || comm_type == return_dock ){

      string course_description;

      if (comm_type == navigation){
			course_description = "navigation";
      } 
      else if (comm_type == speed){
			course_description = "speed";
      }
      else if (comm_type == docking){
			course_description = "docking";
      }
      else if (comm_type == path){
			course_description = "path";
      }
      else if (comm_type == follow){
			course_description = "followLeader";
      }
      else if (comm_type == flag){
			course_description = "flag";
      }
      else if (comm_type == return_dock){
			course_description = "return";
      }

		string filename;
		string http_request;
		filename.append(course_description + "/image/" + course_type + "/" + team_code);
		http_request.append("POST "+ filename +" HTTP/1.1\r\n");
		http_request.append("Content-Type: multipart/form-data; boundary=PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV\r\n");
		http_request.append("Host: " + hostname + ":" + to_string(port_number) + "\r\n");
		http_request.append("Accept: */*\r\n");
		http_request.append("Content-Length: 7280\r\n");
		http_request.append("Expect: 100-continue\r\n\r\n");
	
		http_request.append("--PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV");
		http_request.append("Content-Disposition: form-data; name=flag; filename=../flag.jpg");
		http_request.append("Content-Type: application/octet-stream\r\n");
		http_request.append("c1790bde8f831e7c\r\n");
		http_request.append("--PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV\r\n\r\n");
		
		payload = http_request;
		return true;
   }
   return false;
   
	//> POST /docking/image/courseA/AUVSI HTTP/1.1
	//> Content-Type: multipart/form-data; boundary=PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV
	//> User-Agent: curl/7.38.0
	//> Host: 127.0.0.1:8080
	//> Accept: */*
	//> Content-Length: 7280
	//> Expect: 100-continue
	//>
	//< HTTP/1.1 100 Continue
	//> --PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV
	//> Content-Disposition: form-data; name="file"; filename="test.jpg"
	//> Content-Type: application/octet-stream
	//>
	//> c1790bde8f831e7c
	//> --PqjtwSukItOMmSZ6NSvgT661LL9lxkOHSdnV
	//>
	//< HTTP/1.1 202 Accepted
}

// ####################################################################################################### start of getTime class ########################################## //
class getTime {

	private:
		time_t t;
		struct tm * now;

	public:

		getTime ();
		void refreshTime();
		string getYear();
		string getMonth();
		string getDay();
		string getHour();
		string getMinute();
		string getSecond();
		string getYMDHS();
};

getTime::getTime(){
    t = time(0);   // get time now
    now = localtime( & t );
}

void getTime::refreshTime(){
    t = time(0);   // get time now
    now = localtime( & t );
}

string getTime::getYear(){
    this->refreshTime();
    int year = now->tm_year + 1900;
    return to_string(year);
}

string getTime::getMonth(){
    this->refreshTime();
    int month = now->tm_mon + 1;
    if(month < 10){
      return "0" + to_string(month);
    }
    else {
      return to_string(month);
    }
}

string getTime::getDay(){
    this->refreshTime();
    int day = now->tm_mday;
    if(day < 10){
		return "0" + to_string(day);
    }
    else {
		return to_string(day);
    }
}
  
string getTime::getHour(){
    this->refreshTime();
    int hour = now->tm_hour;
    if(hour < 10){
		return "0" + to_string(hour);
    }
    else {
		return to_string(hour);
    }
}
  
string getTime::getMinute(){
    this->refreshTime();
    int minute = now->tm_min;
    if(minute < 10){
		return "0" + to_string(minute);
    }
    else {
		return to_string(minute);
    }
}
  
string getTime::getSecond(){
    this->refreshTime();
    int second = now->tm_sec;
    if(second < 10){
		return "0" + to_string(second);
    }
    else {
		return to_string(second);
    }
}

string getTime::getYMDHS(){
    string complete_date = this->getYear() + this->getMonth() + this->getDay() + this->getHour() + this-> getMinute() + this->getSecond();
    return complete_date;
}
