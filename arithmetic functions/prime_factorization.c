int mpz_prime_factors(mpz_t n_in, mpz_t * factors)
{
	int  fact_size=0;
	mpz_t i, n, sqrt_n;
	mpz_inits(i,n,sqrt_n,NULL);
	mpz_set(n,n_in);
    if (mpz_odd_p(n)==0) {
    	mpz_set_ui(factors[0],2);
    	fact_size++;
    }
    while (mpz_odd_p(n)==0) mpz_cdiv_q_ui(n,n,2);

	mpz_set_ui(i,3);
	mpz_sqrt(sqrt_n,n);
	while(mpz_cmp(i,sqrt_n)<=0)
    {

       	if (mpz_divisible_p(n,i)!=0){
            mpz_set(factors[fact_size],i);
            fact_size++;
       	}

        while (mpz_divisible_p(n,i)!=0) mpz_divexact(n,n,i);
        mpz_add_ui(i,i,2);
    }

     	if (mpz_cmp_ui(n,2)>0) {
  		mpz_set(factors[fact_size],n);
	  	fact_size++;
	  }

  return fact_size;
}
