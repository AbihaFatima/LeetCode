#### Time Complexity : `O( query_row * query_row )`
     we have to calculate amount of liquid till the very last glass of current row
     
#### Space Complexity : `O((query_row + 1) * (query_row + 1))`
     +1 as liquid from glasses of in-between of current row will be spilled in in-between glasses of next row
