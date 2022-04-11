If k is 1 then new column is (j+1) and if k is k then new column is (j+k) and new column should in range [0,cols-1]. So new column is (j+k) % cols.
<br>
For row, we have to first the find number of rows added to previous row which is equal to the number of times (j+k) exceeds m. So, number of rows added is (j+k)/cols.
<br>
So, new row is (i + (j+k)/m) and new row should in range [0,rows-1]. So new column is (i + (j+k)/cols) % rows.