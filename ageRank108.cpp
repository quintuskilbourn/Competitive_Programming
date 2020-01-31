#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

int main(){
  string max,min,nw;
  int max_month, min_month, max_day, min_day, max_year, min_year, num, day,month,year;

  cin>>num;
  cin>>nw>>max_day>>max_month>>max_year;
  max=nw;
  min=nw;
  min_day=max_day;
  min_month=max_month;
  min_year = max_year;

  for(int i=1; i<num;i++){
    cin>>nw>>day>>month>>year;
    if(year>max_year){
      max_year = year;
      max_month = month;
      max_day = day;
      max = nw;
      continue;
    }else if(year == max_year){
      if(month>max_month){
        max_year = year;
        max_month = month;
        max_day = day;
        max = nw;
        continue;
      }else if(month==max_month){
        if(day>max_day){
          max_year = year;
          max_month = month;
          max_day = day;
          max = nw;
          continue;
        }
      }
    }

    if(year<min_year){
      min_year = year;
      min_month = month;
      min_day = day;
      min = nw;
      continue;
    }else if(year == min_year){
      if(month<min_month){
        min_year = year;
        min_month = month;
        min_day = day;
        min = nw;
        continue;
      }else if(month==min_month){
        if(day<min_day){
          min_year = year;
          min_month = month;
          min_day = day;
          min = nw;
          continue;
        }
      }
    }
  }
  cout<<max<<endl;
  cout<<min<<endl;

  return 0;
}
