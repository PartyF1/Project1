#include "Url.h"

Url::Url() : LitRes()
{
	this->nameRes = "";
	this->url = "";
	this->caller = "";
}

Url::Url(string nameRes) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->url = "";
	this->caller = "";
}

Url::Url(string nameRes, string url) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->url = url;
	this->caller = "";
}

Url::Url(string nameRes, string url, string caller) : LitRes(nameRes)
{
	this->nameRes = nameRes;
	this->url = url;
	this->caller = caller;
}

Url::~Url()
{
}

string Url::getUrl()
{
	return url;
}

string Url::getCaller()
{
	return caller;
}

void Url::setUrl(string url)
{
	this->url = url;
}

void Url::setCaller(string caller)
{
	this->caller = caller;
}

void Url::print(std::ostream& cout)
{
	if(this->nameRes != "")
		cout << this->nameRes << endl;
	if (this->url != "") 
		cout << this->url << endl;
	if (this->caller != "") 
		cout << this->caller << endl;
}

void Url::enter(std::istream& cin)
{
	cout << "¬ведите название интернет-ссылки: ";
	getline(cin, this->nameRes);
	cout << endl;

	cout << "¬ведите URL: ";
	getline(cin, this->url);
	cout << endl;

	cout << "¬ведиет ќбратител€: ";
	getline(cin, this->caller);
	cout << endl;
}
