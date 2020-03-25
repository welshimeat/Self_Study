  #include <stdio.h>

  int inputyear();
  int yearCheck(int);
  void printyear(int);

  int main(){
    int year, check;
    year = inputyear();
    check = yearCheck(year);
    printyear(check);
  }

  int inputyear(){
    int year;
    scanf("%d", &year);
    return year;
  }

  int yearCheck(int year){
    if(year%4 == 0){
      if(year%100 == 0){
        if(year%400 == 0)
          return 1;
        else return 0;
      }
      else return 1;
    }
    else return 0;
  }

  void printyear(int check){
      printf("%d", check);
  }
