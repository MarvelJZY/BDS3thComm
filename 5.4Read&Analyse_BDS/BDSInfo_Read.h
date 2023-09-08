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

//������1//Ӧ���ѾȺ�λ�ñ�����Ϣ
class SenEPI :public BDSInfo
{
public:
	string send_id, recv_id, serv_type, time, lon, lon_mark, lat, lat_mark, height;
	string secure_type, command_type, secure_data_len, state_data_len, state_data;

	void SplitEPI(string str,string*p);//EPI�ָ�
	void DecodeEPI(SenEPI*epi,string *p);//EPI����
private:

};

//�������1//Ӧ���ѾȺ�λ�ñ�������
class SenEPQ :public BDSInfo
{
public:
	string id, serv_type, in_st_freq, in_st_speed, freq_degree, lon, lon_mark, lat, lat_mark, height;
	string secure_type, secure_data_len, secure_data, state_data_len, state_data;

	void GatherEPQ(string str);//EPQ�ϲ�
	void EncodeEPQ(string str);//EPQ����

private:

};

//������2//����ͨ����Ϣ
class SenTCI :public BDSInfo
{
public:
	string send_id, recv_id, time, code_type, data_mark, com_len, com_data;
	
	void SplitTCI(string str, string* p);//TCI�ָ�
	void DecodeTCI(SenTCI*tci,string *p);//TCI����

private:

};


//�������2//����ͨ������
class SenTCQ :public BDSInfo
{
public:
	string id, freq_point, freq_degree, in_st_confirm, code_type, com_len, com_data;

	void GatherTCQ(string str);//TCQ�ϲ�
	void EncodeTCQ(string str);//TCQ����

private:

};

//������3//λ�ò�ѯ�����Ϣ//ͬ���1
class SenSHZ :public BDSInfo
{
public:
	string send_id, recv_id, serv_type, time, lon, lon_mark, lat, lat_mark, height;

	string secure_type, command_type, secure_data_len, state_data_len, state_data;

	void SplitSHZ(string str, string* p);//SHZ�ָ�
	void DecodeSHZ(SenSHZ* shz, string* p);//SHZ����

private:

};

//�������3//λ�ò�ѯ����
class SenPSQ :public BDSInfo
{
public:

	string id, freq_point;

	void GatherPSQ(string str);//PSQ�ϲ�
	void EncodePSQ(string str);//PSQ����

private:

};

//������4//ͨ�Ż�ִ��ѯ�����Ϣ
class SenSAK :public BDSInfo
{
public:
	string send_id, recv_id, report_num;
	string* send_time;

	void SplitSAK(string str);//SAK�ָ�
	void DecodeSAK(string str);//SAK����

private:

};