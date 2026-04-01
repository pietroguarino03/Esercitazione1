#include <iostream>
#include "razionali.hpp"

int main(void)
 {
	/* int n,d;
 rational<int> r(3,6), s(1,5), t;
 n=r.num();
 d=r.den();
 r+=s;
 std::cout<<"operatore +=  :  " << n<<"/"<<d<<" + "<<s<<" = "<<r << "\n";
 r=rational<int>(3,6);
 t=r+s;
 std::cout<<"operatore +  :  " << t << "\n";
 r-=s;
 std::cout<<"operatore -=  :  " << r << "\n";
 r=rational<int>(3,6);
 t=r-s;
 std::cout<<"operatore -  :  " << t << "\n";
 r*=s;
 std::cout<<"operatore *=  :  " << r << "\n";
 r=rational<int>(3,6);
 t=r*s;
 std::cout<<"operatore *  :  " << t << "\n";
 r/=s;
 std::cout<<"operatore /=  :  " << r << "\n";
 r=rational<int>(3,6);
 t=r/s;
 std::cout<<"operatore /  :  " << t << "\n";
 
 return 0;*/
 rational<int> r,s,t;
 bool ancora=true;
 char scelta;
 int n,d;
 while (ancora) {
	 std::cout<<"Scelta operazione:  1 '+=' 2 '+' 3 '-=' 4 '-' 5 '*=' 6 '*' 7 '/=' 8 '/' 9 fine ";
	 std::cin>>scelta;
	 if (scelta!='9'){
		 std::cout<< "num=";
		 std::cin>> n;
		 std::cout<< "den=";
		 std::cin>> d;
		 r=rational<int>(n,d);
		 std::cout<< "num=";
		 std::cin>> n;
		 std::cout<< "den=";
		 std::cin>> d;
		 s=rational<int>(n,d);
		 if (scelta=='1'){
			 r+=s;
			 std::cout<<"operatore +=  :  " << r << "\n";}
		 if (scelta=='2'){
			 t=r+s;
			 std::cout<<"operatore +  :  " << t << "\n";}
		 if (scelta=='3'){
			 r-=s;
			 std::cout<<"operatore -=  :  " << r << "\n";}
		 if (scelta=='4'){
			 t=r-s;
			 std::cout<<"operatore -  :  " << t << "\n";}	 
		 if (scelta=='5'){
			 r*=s;
			 std::cout<<"operatore *=  :  " << r << "\n";}
		 if (scelta=='6'){
			 t=r*s;
			 std::cout<<"operatore *  :  " << r << "\n";}
		 if (scelta=='7'){
			 r/=s;
			 std::cout<<"operatore /=  :  " << r << "\n";}
		 if (scelta=='8'){
			 t=r/s;
			 std::cout<<"operatore *=  :  " << t << "\n";}
	 }
	 else
		ancora=false;
 }
		 
		 
 }