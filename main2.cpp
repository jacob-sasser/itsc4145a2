#include <vector>
#include <iostream>
#include <fstream>
#include "Body.h"
#include <time.h>
std::vector<Body> parseTSV(const std::string& filename) {
     std::vector<Body> bodies;
     std::ifstream file(filename);
     double mass,x,y,z,vx,vy,vz,fx,fy,fz;
     char tab;
     int n=0;
     file>>n;
    while (file >> mass >> x >> y >> z >> vx >> vy >> vz >> fx >> fy >> fz) {
        Body body(x, y, z, mass);
        body.vx = vx;
        body.vy = vy;
        body.vz = vz;
        body.fx = fx;
        body.fy = fy;
        body.fz = fz;
	bodies.push_back(body);
	std::cout<<"Initial:"<<"Mass:"<<body.mass<<", X:"<<body.x<<", Y:"<<body.y<<", Z"<<body.z<<std::endl;
     }
    file.close();
    return bodies;
 }
void output(std::string& filename ,std::vector<Body> bodies,int N){
  std::ofstream o(filename);
  for(auto &body:bodies){
o<<N<<"\t"<<body.mass<<"\t"<<body.x<<"\t"<<body.y<<"\t"<<body.z<<"\t"<<body.vx<<"\t"<<body.vy<<"\t"<<body.vz<<"\t"<<body.fx<<"\t"<<body.fy<<"\t"<<body.fz<<"\t";
  }
  o<<"\n";
}

    int main(int argc,char* argv[]){
      std::string outputfile=(argv[5]);
      srand(time(0));
      int N=std::stoul(argv[1]);
      int steps=std::stoul(argv[2]);
      double dt=std::stoul(argv[3]);
      if(N==0){
	int amt=10;
	std::string filename =argv[4];

	std::vector<Body> bodies= parseTSV(filename);
	
      	for(int i=0;i<steps;i++){
	  if(i%1000==0){output(outputfile,bodies,amt);}
	  for(auto& body:bodies){
	 
	    body.update(bodies,dt);
	    
	  }
	}
      }
      else{
	std::vector<Body> bodies;
	for(int j=0;j<N;++j){//create N bodies
	  
	  double mass=rand();
	  double x=rand();
	  double y=rand();
	  double z=rand();
	  double vx=rand();
	  double vy=rand();
	  double vz=rand();
	  double fx=rand();
	  double fy=rand();
	  double fz=rand();
	  Body body(x,y,z,mass);
	  body.vx=vx;
	  body.vy=vy;
	  body.vz=vz;
	  body.fx=fx;
	  body.fy=fy;
	  body.fz=fz;
	  bodies.push_back(body);
	}
	for(int k=0;k<steps;k++){
	  if(k%1000==0){output(outputfile,bodies,N);}
	for(auto& body:bodies){
	  
	  body.update(bodies,dt);
	  
	}//body
	}//step
       
      }//Else

    return 0;
}
