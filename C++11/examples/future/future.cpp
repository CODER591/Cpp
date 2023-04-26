/*
 * References:
 *
 *   [williams2012] C++ Concurrency in Action
 *     https://www.manning.com/books/c-plus-plus-concurrency-in-action
 *
 *   [petriconi2018] There Is A Better Future - Felix Petriconi [ACCU 2018]
 *     https://youtu.be/L63XGqiNuhI
 *
 *   [parent2017] Future Ruminations
 *     http://sean-parent.stlab.cc/2017/07/10/future-ruminations.html
 *
 *   [grimm2017] std::future Erweiterungen
 *     http://www.grimm-jaud.de/index.php/blog/std-future-erweiterungen
 *
 *   [varun2015] C++11 Multithreading – Part 8: std::future , std::promise and Returning values from Thread
 *     http://thispointer.com/c11-multithreading-part-8-stdfuture-stdpromise-and-returning-values-from-thread/
 */

#include <future>
#include <iostream>

int find_the_answer_to_ltuae()
{
  return 42;
}

void do_other_stuff()
{
}

int main()
{
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout << "The answer is " << the_answer.get() << std::endl;
}
