#include "ex13.5strvec.hpp"
#include <map>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <iterator>

using namespace std;

class QueryResult;

class TextQuery {
public:
    using Line_No = size_t;
    TextQuery(ifstream &infile);
    QueryResult queryWord(const string &word) const;
        
private:
    shared_ptr<StrVec> file_content;
    map<string, shared_ptr<set<Line_No> > > word_detail;
};

class QueryResult {
    friend ostream& printContents(ostream &, const QueryResult &);
public: 
    using Line_No = size_t;
    using SetIterator = set<Line_No>::iterator;
    QueryResult(const string &s, shared_ptr<set<Line_No> > p, 
                shared_ptr<StrVec> f) : 
        to_sought(s), lines(p), file(f) {}
    
    SetIterator  beg() {return lines->begin();} 
    SetIterator  end() {return lines->end();} 
    shared_ptr< StrVec > getFile() {return file;}


    const string to_sought;
    shared_ptr<set<Line_No> > lines;
    shared_ptr< StrVec> file;
};

TextQuery::TextQuery(ifstream &infile) : file_content(new StrVec) {
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
        os << "\t(line " << item + 1 << ")" << *(qr.file->begin() + long(item)  ) << endl; 
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


