class MyArray
{
private:
  int *ary;
  int size;
public:
  MyArray(){ ary=NULL; size=0;}
  MyArray(int s){ ary=new int[s]; size=s;}
  MyArray(const MyArray &br);
  ~MyArray(){ delete [] ary;}
  MyArray &operator=(const MyArray &br);
  bool put(int index, int val);
  bool get(int index, int &getdata);
  int getSize(){ return size;}
  int *getAry(){ return ary;}
};

MyArray::MyArray(const MyArray &br){
  ary = new int[br.size];
  for(int i=0; i<br.size; i++){
    ary[i] = br.ary[i];
  }
  size = br.size;
}

MyArray &MyArray::operator=(const MyArray &br){
  delete [] ary;
  ary = new int[br.size];
  for(int i=0; i<br.size; i++){
    ary[i] = br.ary[i];
  }
  size = br.size;
  return *this;
}

bool MyArray::put(int index, int val){
  if(index<0 || index>=size)
    return false;
  else{
    ary[index] = val;
    return true;
  }
}

bool MyArray::get(int index, int &getdata){
  if(index<0 || index>=size)
    return false;
  else{
    getdata = ary[index];
    return true;
  }
}
