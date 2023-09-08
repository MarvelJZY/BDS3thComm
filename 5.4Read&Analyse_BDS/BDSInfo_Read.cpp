#include "BDSInfo_Read.h"

void SenEPI::SplitEPI(string str, string* p)
{
	char split = ',';
	vector<string> res;
	if (str == "")		return;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + split;
	size_t pos = strs.find(split);

	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}

	//保存各段字符串进入DbsSplited字符串数组
	int i = 0;
	for (auto s : res) //这个时候每个取出来的s只是原来strList元素的副本，不会改变strList中任何元素
	{
		*(p + i) = s;
		i++;
	}
}

void SenEPI::DecodeEPI(SenEPI*epi,string *str)
{
	//cout << *str << endl;
	//SenEPI* epi = new SenEPI();
	cout << "信息类型:"<<epi->message_type << " 发信方:" << epi->send_id << " 收信方:" <<epi->serv_type<< endl;

	
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
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + split;
	size_t pos = strs.find(split);

	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}

	//保存各段字符串进入DbsSplited字符串数组
	int i = 0;
	for (auto s : res) //这个时候每个取出来的s只是原来strList元素的副本，不会改变strList中任何元素
	{
		*(p + i) = s;
		i++;
	}
}

void SenTCI::DecodeTCI(SenTCI* tci,string *str)
{
	cout << "信息类型:" << tci->message_type << " 发信方:" << tci->send_id << " 收信方:" << tci->recv_id << " 时间:" << tci->time << " 编码类别:" << tci->code_type << " 数据标识:" << tci->data_mark << " 通信长度:" << tci->com_len << " 通信数据:" << tci->com_data << endl;
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
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + split;
	size_t pos = strs.find(split);

	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}

	//保存各段字符串进入DbsSplited字符串数组
	int i = 0;
	for (auto s : res) //这个时候每个取出来的s只是原来strList元素的副本，不会改变strList中任何元素
	{
		*(p + i) = s;
		i++;
	}
}

void SenSHZ::DecodeSHZ(SenSHZ* shz, string* str)
{
	cout << "信息类型:" << shz->message_type << " 发信方:" << shz->send_id << " 收信方:" << shz->serv_type << endl;
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

