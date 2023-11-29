#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<fstream>

using namespace std;

struct point{
    int x,y;
};
void find_planar(int start,int length,short *lines,short **max_table,short **line_table){

    int end = start + length;
    max_table[start][end] = max_table[start][end-1];
    line_table[start][end] = line_table[start][end-1];
    //get the new line start
    int new_line_start = lines[end];
    //check  whether the new_line_start is in the range 
    if(new_line_start<start||new_line_start> end){
        return;
    }
    else if(new_line_start == start ){
            //we directly add the new line (start to end) because it will not intersect within the lines in range(start+1)~(end-2)        
            max_table[start][end] = max_table[start+1][end-1] + 1;
            line_table[start][end]= new_line_start; 
    }
    else if(new_line_start == end -1){
            //we directly add the new line (start to end) because it will not intersect within the lines in range(start+1)~(end-2)        
            max_table[start][end] = max_table[start][end-1] + 1;
            line_table[start][end]= new_line_start; 
    }
    else{
        //the range from start~(end-1) and add the line (new_line_start to end) 
        if(max_table[start][new_line_start-1] + max_table[new_line_start+1][end-1] + 1 > max_table[start][end-1]){
            max_table[start][end] = max_table[start][new_line_start] + max_table[new_line_start+1][end-1] + 1;
            line_table[start][end] = new_line_start;
        }

    }
    return;
}
void find_chord(int start,int end,short *lines,bool *first_end,short **line_table,vector<point>& output_line){
     
    point line;
    if(line_table[start][end] == -1) return;

    int mid = line_table[start][end];
    if(first_end[mid])
        line.x = mid,line.y = lines[mid];
    else    
        line.x = lines[mid],line.y = mid;
    //cout<<start<<" "<<end<<" "<<line.x<<" "<<line.y<<endl;
    output_line.push_back(line);
    //the line (mid~lines[mid]) and start<mid<line[mid]<end can separate the circle to three part without the (end to start)
    //first one is start~mid-1 and second one is the mid+1~lines[mid]-1 
    //the third part is line[mid]+1 to end is 0 because if lines exist in line[mid]+1 to end line_table[start][end] will record it 
    if(mid-1 > start){
        find_chord(start,mid-1,lines,first_end,line_table,output_line);
    }
    if(mid+1 < lines[mid]-1){
        find_chord(mid+1,lines[mid]-1,lines,first_end,line_table,output_line);
    }

    return;
}
bool cmp(point a,point b){
    return a.x<=b.x;
}
int main(int argc, char *argv[]){
    int vertice_num;
    int line_num;
    if(argc != 3){
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        exit(1);
    }
    fstream fin;
    
    fin.open(argv[1], fstream::in);
    if(!fin.is_open()){
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }
    fin>>vertice_num;
    line_num = vertice_num/2;

    short *lines = new short[vertice_num];
    bool *first_end = new bool[vertice_num];
    short **max_table = new short*[vertice_num];//record M(i,j) value
    short **line_table = new short*[vertice_num];//record the start point of the line we added

    cout << "======================" << endl;
    cout << "        Parser        " << endl;
    cout << "======================" << endl;
    
    int point1,point2;
    cout << "#Chords:" << vertice_num << endl;
    for(int i = 0;i < line_num;i++){
        fin>>point1>>point2;
        lines[point1]=point2;
        lines[point2]=point1;
        first_end[point1]=true;
        first_end[point2]=false;
        cout << "Chord(" << point1 << "," << point2 << ")" << endl;
    }
    cout<<"1"<<endl;
    //vertice_num*vertice_num
    for(int k = 0;k < vertice_num;k++){
        max_table[k] = new short[vertice_num];
        line_table[k] = new short[vertice_num];
        memset(max_table[k],0,sizeof(short)*vertice_num);
        memset(line_table[k],-1,sizeof(short)*vertice_num);
        
    }
    cout<<"2"<<endl;
    //DP loop is the target range i + length and lenght is from 1~vertice_num
    for(int length = 1;length < vertice_num;length++){
        for(int i = 0;i < vertice_num;i++){         
            if(i + length < vertice_num) 
                find_planar(i,length,lines,max_table,line_table);
        }
    }
    cout<<"3"<<endl;
    vector<point> output_line;
    find_chord(0,vertice_num-1,lines,first_end,line_table,output_line);
    sort(output_line.begin(),output_line.end(),cmp);
    cout<<"4"<<endl;
    fstream fout;
    fout.open(argv[2],fstream::out);
    if(!fout.is_open()){
        cout << "Error: the output file is not opened!!" << endl;
	    exit(1);
    }
    fout<<max_table[0][vertice_num-1]<<endl;
    for(int i = 0;i < output_line.size();i++)
        fout<<output_line[i].x<<" "<<output_line[i].y<<endl;
    cout<<"5"<<endl;
    fout.close();
    delete[] line_table;
    for (int i = 0;i < vertice_num;i++){
        delete[] max_table[i];
        delete[] line_table[i];
    }
    delete[] max_table;
    delete[] line_table;
    return 0;
}
