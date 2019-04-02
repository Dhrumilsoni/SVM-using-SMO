/*
Author: Dhrumil Soni
*/
#include<bits/stdc++.h>
#include"SMO.h"
#include<fstream>
//using namespace std;

int main(){
	int size,dimension;std::cin>>size>>dimension;
	std::fstream in;
	in.open("datasvm.csv");
	std::vector<vector> data;
	std::string get_row;
	for(int i=0;i<60;i++){
		get_row.clear();
		std::getline(in,get_row);
		std::stringstream s(get_row);
		std::string temp;
		std::vector<double> point(dimension);
		for(int i=0;i<dimension;i++){
			std::getline(s,temp,',');
			point[i]=stod(temp);
		}
		std::string st;
		std::getline(s,st,',');
		if(st=="Iris-setosa"){
			vector v(point,1.0);
			data.push_back(v);
		}else{
			vector v(point,-1.0);
			data.push_back(v);
		}
		//data[data.size()-1].print();
	}
	/*
	for(int i=0;i<data.size();i++){
		for(int j=i+1;j<data.size();j++){
			int fl=0;
			for(int k=0;k<data[i].val.first.size();k++){
				if(data[i].val.first[k]!=data[j].val.first[k]){
					fl=1;
 				}
			}
			if(fl==0){
				std::cout<<"same reported";
			}
		}
	}*/
	/*
	for(int i=0;i<size;i++){
		std::vector<double> point(dimension);
		for(int i=0;i<dimension;i++){
			std::cin>>point[i];
		}
		double group;
		std::cin>>group;
		vector v(point,group);
		data.push_back(v);
	}*/
	double c=1000.0,tol=1e-6;
	int max_passes=10;
	compute obj(c,tol,max_passes,data,size);
	obj.get_result();
	//obj.print();
	int cor=0,mis=0;
	for(int i=0;i<40;i++){
		std::vector<double> pdata(dimension,0);
		get_row.clear();
		std::getline(in,get_row);
		std::stringstream s(get_row);
		std::string temp;
		for(int i=0;i<dimension;i++){
			std::getline(s,temp,',');
			pdata[i]=stod(temp);
		}
		//std::cout<<"predicted class "<<obj.predict(pdata,dimension)<<"\n";
		std::string st;
		std::getline(s,st,',');
		if((obj.predict(pdata,dimension)>0.0 && st=="Iris-setosa") || (obj.predict(pdata,dimension)<0.0 && st=="Iris-versicolor")){
			cor++;
		}else{
			mis++;
		}
		/*
		std::cout<<"actual class ";
		if(st=="Iris-setosa"){
			std::cout<<"1.0\n";
		}else{
			std::cout<<"-1.0\n";
		}*/
	}
	std::cout<<"Accuracy "<<(double)cor/(cor+mis)<<"\n";
}