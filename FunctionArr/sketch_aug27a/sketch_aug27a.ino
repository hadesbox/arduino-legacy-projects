
void func1() {  
  printf("Function 1 Called\n"); 
}
void func2() {  
  printf("Function 2 Called\n"); 
}
void func3() {  
  printf("Function 3 Called\n"); 
}

static void (*ptr[3])() = {func1,func2,func3};

void setup(){


}

void loop(){
  for(int k=0;k<3;k++){
    ptr[k]();
  }
}



