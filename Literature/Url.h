#pragma once
#include "LitRes.h"
class Url: public LitRes
{
private:
	string url;
	string caller;
public:
	Url();
	Url(string nameRes);
	Url(string nameRes, string url);
	Url(string nameRes, string url, string caller);
	~Url();

	string getUrl();
	string getCaller();

	void setUrl(string url);
	void setCaller(string caller);

	void print(std::ostream& cout);
	void enter(std::istream& cin);

};

