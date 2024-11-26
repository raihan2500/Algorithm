# Unknow fact of Mod
মনে করি, 
    n = ৩৫ একটি নাম্বার
    সুতরাং n = ৫ * ৭ 

এখন m = 2000000014 * ৭ = 14000000098  অনেক বড় একটি নাম্বার যার ও একটি ভাজক ৭
এখন আমরা যদি m কে n দিয়ে mod করি তাহলে যে সংখ্যাটি পাবো তাকে ও ৭ দিয়ে ভাগ করা যাবে
যেমন,
       m = m % n
    => m = ২৮ 

That means still the properties are remain in m even after moding by n, That is interesting


# Primality Test
Is p prime

Test:
if p is a prime number then for all a from (1 to p - 1)
    (a^p - a % p) == 0