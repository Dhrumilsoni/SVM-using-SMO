#include<bits/stdc++.h>
#include"SMO.h"
//using namespace std;

int main(){
	int size,dimension;std::cin>>size>>dimension;
	std::vector<vector> data;
	for(int i=0;i<size;i++){
		std::vector<double> point(dimension);
		for(int i=0;i<dimension;i++){
			std::cin>>point[i];
		}
		double group;
		std::cin>>group;
		vector v(point,group);
		data.push_back(v);
	}
	compute obj(0.1,0,5,data,size);
	obj.get_result();
	obj.print();
	std::vector<double> pdata(dimension,0);
	for(int i=0;i<dimension;i++){
		std::cin>>pdata[i];
	}
	std::cout<<"\n"<<obj.predict(pdata,dimension);
}