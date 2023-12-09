#include <stdio.h>

int i,j,start_row,start_col,end_row,end_col,n ;
char maze[100][100];
int nummaze[100][100];
int solution[100][100];

//function solve maze
int traverseMaze(int start_row,int start_col) {
    //goal
   if( (start_row == end_row) && (start_col == end_col) ) {
      solution[start_row][start_col] = 1;
      return 1;
   }
   //travel
   else if(start_row>=0 &&  start_col>=0 && start_row<n &&  start_col<n && solution[start_row][start_col] == 0 && nummaze[start_row][start_col] == 0){
      solution[start_row][start_col] = 1;
      //going left
      if(traverseMaze(start_row,  start_col-1))
         return 1;
      //going down
      if(traverseMaze(start_row+1,  start_col))
         return 1;
      //going right
      if(traverseMaze(start_row,  start_col+1))
         return 1;
      //going up
      if(traverseMaze(start_row-1,  start_col))
         return 1;
      //backtracking
      solution[start_row][ start_col] = 0;
      return 0;

   }
   return 0;
}





int main(){
    
	scanf("%d ",&n);
	
    ////input maze 
    char c[100];
    for(i=0;i<n;i++){
        char c[100];
        fgets(c , 100 , stdin);
        for (j=0;j<n;j++){
			maze[i][j] = c[j];
            //create matrix
			nummaze[i][j] = 0;
            solution[i][j] = 0;
        
		}
    }
    
    //find start,end
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (maze[i][j] == 'S' ){
                start_row = i;
                start_col = j;
                //printf("%d %d\n",start_row,start_col);
            }
            if (maze[i][j] == 'G' ){
                end_row = i;
                end_col = j;
                //printf("%d %d\n",end_row,end_col);
            }
            if (maze[i][j] == '#' ){
                nummaze[i][j] = 1;
            }
            else {
                nummaze[i][j] = 0;
            }
            
        }
    }
    
    //solve
    traverseMaze(start_row,start_col);
    //print maze
    
    /*
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("%c",maze[i][j]);
	    }
	    printf("\n");
	}
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("%d",nummaze[i][j]);
	    }
	    printf("\n");
	}
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("%d",solution[i][j]);
	    }
	    printf("\n");
	}
    */
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        if (solution[i][j] == 1){
                maze[i][j] = '.';
            }
	    }
	}
    
    maze[start_row][start_col] = 'S';
    maze[end_row][end_col] = 'G';
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("%c",maze[i][j]);
	    }
	    printf("\n");
	}
    
    
    return 0;
}