#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {

    //input
    ifstream in("text.in");

    string fraza;
    char c;
    while (in.get(c)) {
        fraza += c;
    }

    //make everything lowercase
    for (char &iterator: fraza) {
        if (iterator > 64 && iterator < 91) {
            iterator += 32;
        }
    }

    //create map
    map<string, int> cuvinte;
    const char separatori[] = " ,?!.";
    size_t startPos = 0, finPos ;

    while (true) {
        finPos = fraza.find_first_of(separatori, startPos);
        if (finPos == string::npos) break;
        string cuvant = fraza.substr(startPos, finPos - startPos);
        cuvinte[cuvant]++;
        startPos = fraza.find_first_not_of(separatori, finPos);
    }

    //create Compare functionality
    struct Compare {
        bool operator()(pair<string, int> a, pair<string, int> b) const {
            if (a.second > b.second) return false;
            if (a.second < b.second) return true;

            auto asize = a.first.size();
            auto bsize = b.first.size();
            if (a > b) return false;
            if (a < b) return true;
            for (auto i = 0; i < min(asize, bsize); i++) {
                if (a.first[i] > b.first[i]) return false;
                if (a.first[i] < b.first[i]) return true;
            }
            return true;
        }
    };

    //create priority queue
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> coada;

    for (auto iterator: cuvinte) {
        pair<string, int> temp;
        temp.first = iterator.first;
        temp.second = iterator.second;
        coada.push(temp);
    }

    //output
    auto coadaCopy = coada;

    while(coadaCopy.empty() == false){
        auto temp = coadaCopy.top();
        cout<<temp.first<<" => "<<temp.second<<'\n';
        coadaCopy.pop();
    }

    return 0;
}
