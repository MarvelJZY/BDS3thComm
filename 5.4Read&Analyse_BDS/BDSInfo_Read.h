#pragma once

#include <string>
using namespace std;
#include <iostream>
#include <vector>

class BDSInfo
{
public:
	//string* param;
	string str_input;
	string str_output;
	string message_type;
private:

};

//输出语句1//应急搜救和位置报告信息
class SenEPI :public BDSInfo
{
public:
	string send_id, recv_id, serv_type, time, lon, lon_mark, lat, lat_mark, height;
	string secure_type, command_type, secure_data_len, state_data_len, state_data;

	void SplitEPI(string str,string*p);//EPI分割
	void DecodeEPI(SenEPI*epi,string *p);//EPI解析
private:

};

//输入语句1//应急搜救和位置报告申请
class SenEPQ :public BDSInfo
{
public:
	string id, serv_type, in_st_freq, in_st_speed, freq_degree, lon, lon_mark, lat, lat_mark, height;
	string secure_type, secure_data_len, secure_data, state_data_len, state_data;

	void GatherEPQ(string str);//EPQ合并
	void EncodeEPQ(string str);//EPQ编码

private:

};

//输出语句2//报文通信信息
class SenTCI :public BDSInfo
{
public:
	string send_id, recv_id, time, code_type, data_mark, com_len, com_data;
	
	void SplitTCI(string str, string* p);//TCI分割
	void DecodeTCI(SenTCI*tci,string *p);//TCI解析

private:

};


//输入语句2//报文通信申请
class SenTCQ :public BDSInfo
{
public:
	string id, freq_point, freq_degree, in_st_confirm, code_type, com_len, com_data;

	void GatherTCQ(string str);//TCQ合并
	void EncodeTCQ(string str);//TCQ编码

private:

};

//输出语句3//位置查询结果信息//同输出1
class SenSHZ :public BDSInfo
{
public:
	string send_id, recv_id, serv_type, time, lon, lon_mark, lat, lat_mark, height;

	string secure_type, command_type, secure_data_len, state_data_len, state_data;

	void SplitSHZ(string str, string* p);//SHZ分割
	void DecodeSHZ(SenSHZ* shz, string* p);//SHZ解析

private:

};

//输入语句3//位置查询申请
class SenPSQ :public BDSInfo
{
public:

	string id, freq_point;

	void GatherPSQ(string str);//PSQ合并
	void EncodePSQ(string str);//PSQ编码

private:

};

//输出语句4//通信回执查询结果信息
class SenSAK :public BDSInfo
{
public:
	string send_id, recv_id, report_num;
	string* send_time;

	void SplitSAK(string str);//SAK分割
	void DecodeSAK(string str);//SAK解析

private:

};