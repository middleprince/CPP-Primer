#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include "strBlobModule.h"

using namespace std;

class QueryResult;

class TextQuery {
public:
    using Line_No = vector<string>::size_type;
    TextQuery(ifstream &infile);
    QueryResult queryWord(const string &word) const;
        
private:
    shared_ptr<StrBlob > file_content;
    map<string, shared_ptr<set<Line_No> > > word_detail;
};

class QueryResult {
    friend ostream& printContents(ostream &, const QueryResult &);
public: 
    using Line_No = vector<string>::size_type;
    QueryResult(const string &s, shared_ptr<set<Line_No> > p, 
                shared_ptr<StrBlob > f) : 
        to_sought(s), lines(p), file(f) {}
    
    const string to_sought;
    shared_ptr<set<Line_No> > lines;
    shared_ptr<StrBlob > file;
};

TextQuery::TextQuery(ifstream &infile) : file_content(new StrBlob) {
    string line;
    
    while (getline(infile, line)) {
        file_content->push_back(line);
        Line_No line_no = file_content->size() - 1;  
        
        string word;
        istringstream words(line); 
        while (words >> word) {
            auto &lines = word_detail[word]; 
            // the trist word occured , lines will point tonullptr, 
            //  allocate a set memeory for line number
            if ( !lines) 
                lines.reset(new set<Line_No>);
            lines->insert(line_no);
        }
    }
    //cout << "#Debug in TextQuery constructor" << endl;
}

QueryResult
TextQuery::queryWord(const string &word) const {
    static shared_ptr<set<Line_No> > nodata(new set<Line_No>);
    auto location = word_detail.find(word); 
    if (location == word_detail.end()) 
        return QueryResult(word, nodata, file_content);
    else
        return QueryResult(word, location->second, file_content);
}

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.to_sought << " ocuur " << qr.lines->size()
        << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;

    for (auto item : *qr.lines) {
        os << "\t(line " << item + 1 << ")" 
            << (qr.file->begin() + item).deref() << endl; 
    }
    return os;
    }

void runQuery(ifstream &infile) {
    TextQuery tq(infile);
    
    while (true) {
        cout << "input the word you want to query, or q to quiet: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        //cout << "#Debug is runQury to found: " << s << endl;
        print(cout, tq.queryWord(s)) <<endl;
    
    }
}


int main(int argc, char **argv) {
    if (argc != 2)
        throw runtime_error("the argument count must be 2\n");
    ifstream infile(argv[1]);
    runQuery(infile);

    return 0;
    
}


