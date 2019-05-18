                int i = 1;
                int newPos = index;
                while(database[newPos] != 0){
                    newPos = index;
                    int quadratic = pow(i, 2);
                    newPos = (index + quadratic) % NUM_OF_INDEX;
                    i++;
                }
                database[newPos] = data;