/* Nilesh Singh
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int distance( std::string word, std::string toCheck){
  int i = 0, count = 0;
      while (i<word.size())
      {
          if (word[i] != toCheck[i])
              count++;
          i++;
      }
      return count;
}
int distance2 ( std::string word, std::string toCheck){
    int i = 0, j=0,count = 0;

          while (i<word.size())
          {
              if (toCheck[j] != word[i]){
                count++;
              }
              else j++;
              i++;
              }

              if(count>1)
              return 2;
              else
              return 1;
      }

      int distance3 ( std::string word, std::string toCheck){
          int i = 0, j=0,count = 0;

                while (i<toCheck.size())
                {
                    if (word[j] != toCheck[i]){
                        count++;
                  }
                    else j++;
                          i++;
                    }

                    if(count>1)
                    return 2;
                    else
                    return 1;

            }

int main (int argc, char* argv[]) {

  if (argc != 2) {
    return 1;
  }
  std::ifstream file(argv[1]);
  std::map<std::string, int> dicts;

    std::string line;
    while (getline(file, line)){
      std::string word="";
      std::string num ="";

      for (auto i = 0; i < line.size(); ++i){
        if (line[i] == ' ')
        {
          while(i<line.size()){
          num += line[i+1];
          i++;}
        }
        else{
            word += line[i];
          }
        }
        // std::cout << "num="<<num << " word" << word  << std::endl;
        auto n =0;
        if(num!="")
        n = std::stoi(num, nullptr);
        dicts.insert(std::pair<std::string,int>(word, n));
    }
    file.close();

  std::string word;
  while (std::cin >> word) {

    int coun = 0;
    std::string Inword =word;



    for(auto it= dicts.begin();it!=(dicts.end());it++){
    if (it->first == word) {
              std::cout << word << " " << it->second << std::endl;
              coun=-20;
              dicts[word]++;
                  break;
  }
  else{
    if(word.size()==it->first.size()){
    if(distance(word, it->first)==1){
        if (it->second > coun) {
             coun = it->second;
             Inword = it->first;
           }
    }
  }
  else {
    if(word.size()==it->first.size()+1){
    if(distance2(word, it->first)==1){
     if (it->second > coun) {
          coun = it->second;
          Inword = it->first;
        }
      }
 }
 if(word.size()+1==it->first.size()){
 if(distance3(word, it->first)==1){
  if (it->second > coun) {
       coun = it->second;
       Inword = it->first;
     }
   }
}
 }
}
}


    if(coun==0){
       std::cout << "-" << std::endl;
       dicts.insert(std::pair<std::string,int>(Inword, 1));
    }
    else if(coun != -20) {
      std::cout << Inword << " " << dicts[Inword] << std::endl;
    }
  }

  return 0;
}
