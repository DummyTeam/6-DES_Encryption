# 6-Encryption
Data Encryption Standard algorithm written in C++
                                                                                                    
     -hhhhhhhhhhhhhhhhh:             +hhhhhhhhhhhhhhhhhhhhhhh/          shhhhhhhhhhhhhs +hhhh.      
     :NNNNNNNNNNNNNNNNNo--.          oNNNNNNNNNNNNNNNNNNNNNNN+       .--dNNNNNNNNNNNNNd-yNNNN-      
     `--/NNNNh-------/NNNNy          .--sNNNNo----------+NNNN+       mNNNm-----------dNNNNNNN-      
        .NNNNh       .yyyNmyyo          +NNNN+          .yyyy/       mNNNd           syydNNNN-      
        .NNNNh           NNNNh          +NNNN+    `....              mNNNd              oNNNN-      
        .NNNNh           NNNNh          +NNNN+    hmmmm`             mNNNd              .::::`      
        .NNNNh           NNNNh          +NNNNy++++mNNNN`             hddNm+++++++++-                
        .NNNNh           NNNNh          +NNNNNNNNNNNNNN`             ```hNNNNNNNNNNo``````          
        .NNNNh           NNNNh          +NNNNy++++mNNNN`                :+++++++++Nmdddddd`         
        .NNNNh           NNNNh          +NNNN+    ymmmm`                         `mmmmmmmN///`      
        .NNNNh           NNNNh          +NNNN+    `....                           ......sNNNN-      
        .NNNNh           NNNNh          +NNNN+                       yhhhy              oNNNN-      
        .NNNNh       `---NNNNh          +NNNN+          `----`       mNNNm---           oNNNN-      
        .NNNNh       -mmmNh--.          +NNNN+          -mmmm+       mNNNNmmm.          oNNNN-      
     .yyyNNNNmyyyyyyyhNdyy+          /yydNNNNdyyyyyyyyyyhNNNN+       mNNNNydNyyyyyyyyyyydNhyy.      
     :NNNNNNNNNNNNNNNNN/             sNNNNNNNNNNNNNNNNNNNNNNN+       mNNNm oNNNNNNNNNNNNNN`         
     `/////////////////.             -///////////////////////.       :///: .//////////////          
                                                                                                    
The Data Encryption Standard is a symmetric-key algorithm for the encryption of electronic data.

## How DES works

- Message (string text)
- Key (string text)
- Convert message and key to binary (string binary)

Key generation (16 keys needed)
- Run the binary key through PC-1 table (From 64 to 56 bit)
- Split the resulting 56bit key into 2 parts C and D
- Keys should be shifted to left 1 or 2 bits 16 times to generate other keys. Number of left shifts is determined with a table.
- After getting 16 pairs of C and D sets, concatenate them
- Run the resulting keys through PC-2
  // 16 keys for each round.

Encyription algorithm
- Split binary message to 64 bit chunks
- Run 64 bit data through IP (initial permutation)
- Divide message into to parts: L(left) and R(right)
- Run these formulas for 16 rounds
		L(n) = R(n-1);
		R(n) = L(n-1) + f(R(n-1), K(n)); // '+' is XOR operation 
	- f function first expanpandes R from 32 bit to 48 bit (run through E selection table)
	- f function then apply XOR operation: (R(n-1)^K(n))
	- f function then runs the result (8 times 6 bits = 48 bit) through 8 S boxes. 
    S box is type of table. First and last bits help to find row and middle 4 bits help to find column.
    Table outputs 4 bit data.
	- f function, finally, passes the 32 bit result through a Permutation Function

- After finding L(16) and R(16), order should be reversed and concatenated like this:
	R(16)L(16)
- Concatinated string should be passed through final permutation IP(-1) table

Decryption is simply the inverse of encryption, follwing the same steps as above, but reversing the order in which the subkeys are applied.

- Visual Studio 2017 Community version
- C++
