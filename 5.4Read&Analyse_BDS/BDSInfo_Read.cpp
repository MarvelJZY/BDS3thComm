#include "BDSInfo_Read.h"

void SenEPI::SplitEPI(string str, string* p)
{
	char split = ',';
	vector<string> res;
	if (str == "")		return;
	//���ַ���ĩβҲ����ָ����������ȡ���һ��
	string strs = str + split;
	size_t pos = strs.find(split);

	// ���Ҳ����������ַ��������������� npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}

	//��������ַ�������DbsSplited�ַ�������
	int i = 0;
	for (auto s : res) //���ʱ��ÿ��ȡ������sֻ��ԭ��strListԪ�صĸ���������ı�strList���κ�Ԫ��
	{
		*(p + i) = s;
		i++;
	}
}

void SenEPI::DecodeEPI(SenEPI*epi,string *str)
{
	//cout << *str << endl;
	//SenEPI* epi = new SenEPI();
	cout << "��Ϣ����:"<<epi->message_type << " ���ŷ�:" << epi->send_id << " ���ŷ�:" <<epi->serv_type<< endl;

	
}

void SenEPQ::GatherEPQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenEPQ::EncodeEPQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenTCI::SplitTCI(string str, string* p)
{
	char split = ',';
	vector<string> res;
	if (str == "")		return;
	//���ַ���ĩβҲ����ָ����������ȡ���һ��
	string strs = str + split;
	size_t pos = strs.find(split);

	// ���Ҳ����������ַ��������������� npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}

	//��������ַ�������DbsSplited�ַ�������
	int i = 0;
	for (auto s : res) //���ʱ��ÿ��ȡ������sֻ��ԭ��strListԪ�صĸ���������ı�strList���κ�Ԫ��
	{
		*(p + i) = s;
		i++;
	}
}

void SenTCI::DecodeTCI(SenTCI* tci,string *str)
{
	cout << "��Ϣ����:" << tci->message_type << " ���ŷ�:" << tci->send_id << " ���ŷ�:" << tci->recv_id << " ʱ��:" << tci->time << " �������:" << tci->code_type << " ���ݱ�ʶ:" << tci->data_mark << " ͨ�ų���:" << tci->com_len << " ͨ������:" << tci->com_data << endl;
}

void SenTCQ::GatherTCQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenTCQ::EncodeTCQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenSHZ::SplitSHZ(string str, string* p)
{
	char split = ',';
	vector<string> res;
	if (str == "")		return;
	//���ַ���ĩβҲ����ָ����������ȡ���һ��
	string strs = str + split;
	size_t pos = strs.find(split);

	// ���Ҳ����������ַ��������������� npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}

	//��������ַ�������DbsSplited�ַ�������
	int i = 0;
	for (auto s : res) //���ʱ��ÿ��ȡ������sֻ��ԭ��strListԪ�صĸ���������ı�strList���κ�Ԫ��
	{
		*(p + i) = s;
		i++;
	}
}

void SenSHZ::DecodeSHZ(SenSHZ* shz, string* str)
{
	cout << "��Ϣ����:" << shz->message_type << " ���ŷ�:" << shz->send_id << " ���ŷ�:" << shz->serv_type << endl;
}

void SenPSQ::GatherPSQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenPSQ::EncodePSQ(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenSAK::SplitSAK(string str)
{
	cout << "function didnt realize!" << endl;
}

void SenSAK::DecodeSAK(string str)
{
	cout << "function didnt realize!" << endl;
}

