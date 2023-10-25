#include<iostream>
using namespace std;
int main() {
   int blockNumber = 5, processesNumber = 3;
   int blockSize[5] = {4, 4, 4, 4, 4}, processSize[3] = {1, 2, 3};
   int flags[5], allocation[5];
   for(int i = 0; i < 5; i++) {
      flags[i] = 0;
      allocation[i] = -1;
   }

   for(int i = 0; i < processesNumber; i++) {
      for(int j = 0; j < blockNumber; j++) {
         if(flags[j] == 0 && blockSize[j] >= processSize[i]) {
            allocation[j] = i;
            flags[j] = 1;
            break;
         }
      }
   }
   for (int i = 0; i < blockNumber; i++) {
      if (flags[i] == 1) {
         cout << "Process " << processSize[allocation[i]] << " is allocated" << endl;
      }
   }
   return 0;
}
