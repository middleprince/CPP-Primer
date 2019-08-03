#ifndef TextQuery_h
#define TextQuery_h

#include <iostream>
#include <fstream>
using std::ifstream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

#include <set>
#include <map>
#include <vector>
using std::vector;
using std::set;
using std::map;

#include <string>
#include <sstream>
using std::string;

#include <memory>
using std::shared_ptr;
#include <iterator>



//-----------------------------------------------------------------------------
//      Class QueryResult
//      @functioning: the class contians the information about the word and 
//          line_no description, which for pass these information for operator
//          << to print.
//-----------------------------------------------------------------------------

class QueryResult {
    friend ostream& operator<<(ostream &, const QueryResult &);
public: 
    using Line_No = vector<string>::size_type;
    using SetIterator = set<Line_No>::iterator;
    
    QueryResult(const string &s, shared_ptr<set<Line_No> > p, 
                shared_ptr<vector<string> > f) : 
        to_sought(s), lines(p), file(f) {}
    
    // iterator for line_no
    SetIterator  begin() {return lines->begin();} 
    SetIterator  end() {return lines->end();} 
    shared_ptr<vector<string> > getFile() {return file;}

private:
    const string to_sought;
    shared_ptr<set<Line_No> > lines;
    shared_ptr<vector<string> > file;
};


//-----------------------------------------------------------------------------
//      Class TextQuery
//      @functoning: class to transfer file to "useful" format to doing the 
//          finding operationg.
//-----------------------------------------------------------------------------

class TextQuery {
public:
    using Line_No = vector<string>::size_type;
    TextQuery(ifstream &infile);
    QueryResult queryWord(const string &word) const;

private:
    shared_ptr<vector<string> > file_content;
    map<string, shared_ptr<set<Line_No> > > word_detail;
};


TextQuery::TextQuery(ifstream &infile) : file_content(new vector<string>) {
    string line;
    
    while (getline(infile, line)) {
        file_content->push_back(line);
        Line_No line_no = file_content->size() - 1;  
        
        string word;
        std::istringstream words(line); 
        while (words >> word) {
            // store the line_no into map, which will reuturn the pointer 
            //  pionted to set that contains line_no of the word.
            auto &lines = word_detail[word]; 

            // allocate new memory first time which the word occours for the 
            //  fisrt time.
            if ( !lines) 
                lines.reset(new set<Line_No>);
            lines->insert(line_no);
        }
    }
    //cout << "#Debug in TextQuery constructor" << endl;
}

QueryResult
TextQuery::queryWord(const string &word) const {
    // for no word found
    static shared_ptr<set<Line_No> > nodata(new set<Line_No>);
    // using find inseatd of underline index to acess item, becuase  
    //  accessing item by using index will cause a little "bug", which means
    //  when there is no data index point to, it will constructe a initialize a
    //  pair of these type .
    auto location = word_detail.find(word); 
    if (location == word_detail.end()) 
        return QueryResult(word, nodata, file_content);
    else
        return QueryResult(word, location->second, file_content);
}


//-----------------------------------------------------------------------------
//          help function  
//-----------------------------------------------------------------------------

ostream & operator<<(ostream &os, const QueryResult &qr) {
    os << qr.to_sought << " ocuur " << qr.lines->size()
        << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;

    for (auto item : *qr.lines) {
        os << "\t# (line " << item + 1 << ")" << *(qr.file->begin() + long(item)  ) << endl; 
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
        cout << tq.queryWord(s) << endl;
    
    }
}


#endif


