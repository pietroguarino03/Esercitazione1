#include <iostream>
#include <string>
#include <fstream>
//using namespace std;
 int main(int argc, const char *argv[])
 {std::string citta, t[4];
  int i;
  float media=0, v;
  
 if (argc==1)
		{
			std::cerr<<"nome file assente"<<"\n";
			return 1;
		}
 std::ifstream ifs(argv[1]);
	if ( ifs.is_open() ) 
		{ 
			while (ifs >> citta){
				for (i=0; i<4; i++){
					ifs>>v;
					media+=v;
				}
				media=media/4;
				
				std::cout<< citta<<std::string(20-citta.length(),' ')<<media<<"\n";
				media =0;
			}
			ifs.close();
		return 0;	
		}
	else {
		std::cout<<"errore apertura file"<<"\n";
		return 1;
	}	
}
