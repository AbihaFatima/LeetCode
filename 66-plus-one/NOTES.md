traverse digits from the last element (least significant)
since we begin with the last digit, increasing that digit by one
results in overflow.  Therefore, all elements PRIOR to digits[0]
need to be considered since there may be additional nines between
digits[0], ... , digits[n].