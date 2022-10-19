//Project UID db1f506d06d84ab787baf250c265e24e


#include <cassert>  //assert
#include <utility>  //pair
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include "csvstream.h"


using std::log;
using std::set;
using std::map;

using namespace std;

class Classifier {
   

    public:




void Initialize(string debugval,
                string file){
    
    
    
    map<string, string> readinval;
    csvstream cv(file);

    if("--debug" == debugval){
        cout << "training data:" << endl;
    }
    string tags;
    
    set<string> uniqwords;
    while(cv >> readinval){
        uniqwords = unique_words(readinval["content"]);
        
        
        tags = readinval["tag"];
        ++total_posts;
        if ("--debug" == debugval){
            cout << "  label = ";
            cout << tags;
            cout<< ", " << "content = ";
            cout << readinval["content"] << endl;
        }

        posts_with_label.insert({tags, 0});
        posts_with_label[tags] = 1 + posts_with_label[tags];
        specific_labels.insert(tags);
    
    

 for (auto i = uniqwords.begin(); !(i == uniqwords.end()); i++) {
        specific_words.insert(*i);
        posts_with_word.insert({*i, 0});
        posts_with_word[*i] = 1 + posts_with_word[*i];
        posts_with_label_with_word.insert({pair<string,string>(tags, *i), 0});

        posts_with_label_with_word[pair<string, string>(tags, *i)]
     = 1 + posts_with_label_with_word[pair<string, string>(tags, *i)] ;
                

    }
    }

            int wordssize = (int)specific_words.size();
            cout << "trained on" << " ";
            cout << total_posts;
            cout << " examples";

     if(debugval != "--debug") {
                cout << "\n";
                cout << endl;
     }
    else {
        cout << endl;
    }
    if (debugval == "--debug"){
                cout << "vocabulary size" << " = ";
                cout << wordssize;
                cout << "\n";
                cout << endl;
        }
}







void test(string file){
        csvstream cv(file);
        double correct_amount = 0;
        double amount = 0;
        string words;
        string labels;
        map<string,string> readin;
    cout << endl << "test data:" << endl;
        while(cv >> readin){
            labels = readin["tag"];
            words = readin["content"];
            pair<double, string> logans = log_likelihood(words);
            cout <<  "  ";
            cout << "correct";
            cout << " = ";
            cout << labels;
            cout << "," << " predicted = ";
            cout << logans.second;
            cout << ", log-probability score";
            cout << " = " << logans.first;
            cout << endl;
            cout <<  "  ";
            cout << "content = " << readin["content"];
            cout << endl;
            amount = amount + 1;
         if(logans.second == labels){
             correct_amount = correct_amount + 1;
             
         }
            cout << endl;
            
        }
    
         cout << "performance: ";
         cout << correct_amount << " / ";
         cout << amount;
         cout << " " << "posts predicted correctly";
         cout << endl;
        }

    









double log_prior(string tag){

    double prob_label = log((double)posts_with_label[tag]/total_posts);
    return prob_label;
}

pair<double,string> log_likelihood(string content){
       


        double likelyword = 0.0;
        set<string> no_duplicates = unique_words(content);
        vector<pair<double,string>> answer;
        
        string current_max_label;
        for (auto i = specific_labels.begin(); !(i == specific_labels.end()); ++i) {
            likelyword = 0;
            
            string second = *i;
            double finish = posts_with_label[*i];
            likelyword = likelyword + log((double)finish/total_posts);
            
        


            for(auto it = no_duplicates.begin(); !(it == no_duplicates.end()); it++){
                double done =
                posts_with_label_with_word[pair<string,string>(second,*it)];
                if(0 == done){
                    double won = posts_with_word[*it];
                    if(won == 0)
                        likelyword = likelyword + log((double)1.0/total_posts);
                    else
                     likelyword = likelyword + log((double)won/total_posts);
                }
                else {
                     likelyword = likelyword + log((double)done/finish);
                }
            }
        
            pair<double,string> complete(likelyword,second);

            answer.push_back(complete);
        }
            
            double current_max = 0;
            double max = answer[0].first;
            for(int i = 0; i < answer.size(); ++i){
               if(max < answer[i].first){
                    current_max = i;
                    max = answer[i].first;
                    
                }
            }

           double max_answer = current_max;
           return answer[max_answer];


        }




 set<string> unique_words(const string &str) {
 istringstream source(str);
 set<string> words;
 string word;
 while (source >> word) {
   words.insert(word);
 }
 return words;
 }


void cout_stuff(){
    cout << "classes:";
    cout << endl;
    int labels = 0;
    for(auto i = specific_labels.begin(); !(i == specific_labels.end()); ++i){

        labels = posts_with_label[*i];
    

    double output = log((double)labels/total_posts);
    cout << "  ";
    cout << *i;
    cout << ", " << labels;
    cout << " examples, log-prior" << " = " << output << endl;
    }
}

void cout_stufftwo(){
    cout << "classifier parameters:";
    cout << endl;
   

    double output2;
    for(auto i = specific_labels.begin(); !(i == specific_labels.end()); ++i){
        for(auto it = specific_words.begin(); !(it == specific_words.end()); ++it){
            int words = posts_with_label_with_word[pair<string,string>(*i,*it)];
             if (!(words == 0)){
                output2 = log((double)words/posts_with_label[*i]);
                cout << "  ";
                cout << *i;
                cout << ":" << *it;
                cout << "," << " count";
                cout << " = ";
                cout << words;
                cout << ", log-likelihood" << " = ";
                cout << output2 << endl;
            }
        }
        
    }
}

 private:
    int total_posts;
    map<string, int>  posts_with_word;
    vector<pair<pair<string, string>, int>> read_in_count;
    vector<pair<double, string>> formax;
    map<string, int> posts_with_label;
    map<pair<string,string>,int> posts_with_label_with_word;
    map <string, double> prob_label;
    set<string> specific_words;
    set<string> specific_labels;
    

};

int main(int argc, char* argv[]){
    

    cout.precision(3);
    

    if ( ! (argc == 3 || argc == 4)){
         cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
         return -1;
     }
     if(argc == 4 && string(argv[3]) != "--debug"){
         cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
         return -1;
     }

         

         string train_file = argv[1];
         string test_file = argv[2];
         csvstream train(train_file);
         csvstream test(test_file);
         
        string debugval = "";
        if(argc == 4) debugval = string(argv[3]);

    

        
         

         Classifier abc;
         

         abc.Initialize(debugval, train_file);
         abc.cout_stuff();
         abc.cout_stufftwo();
         abc.test(test_file);
        

 

         return 0;
}
