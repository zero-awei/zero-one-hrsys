#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:09:15
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _TRY_CACTH_FINALLY_
#define _TRY_CACTH_FINALLY_
#include <exception>

/** A nifty try catch finally construction made possible by c++11's new lambda functions.
 *  It behaves just like you would want a try-catch-finally to behave, with a few minor
 *  querks. Firstly you can only catch one type of exception, the base type
 *  of all your exceptions, and if you want to know its type you dynamic cast its pointer.
 *
 *  The default usage, which catches std::exception and has no code looks like this:
 *
 *  TryFinally(
 *      []{},                           // Try body
 *      [](const std::exception &){},   // Catch body
 *      []{});                          // Finally body
 *
 *  Note that the catch function should handle with a const reference, because it
 *  allows you to check which type the exception instance is.
 *
 *  If you want to catch a custom exception type other than std::exception, call it "MyException",
 *  it looks like this:
 *
 *  TryFinally<MyException>(
 *      []{},                       // Try body
 *      [](const MyException &){},  // Catch body
 *      []{});                      // Finally body
 *
 *  \tparam EXCEPTION The type of exception which will be caught. If an exception is thrown that
 *              doesn't derive from this base type, the finally body will be executed but not the catch.
 *  \param ___try The try body. This is executed first. Exceptions thrown here will be handled by the catch body.
 *  \param ___catch The catch body. This is only executed if an exception was thrown inside the try block.
 *          It is required to take the handled exception class as an argument.
 *  \param ___finally The finally body. This is executed regardless of whether an exception was thrown,
 *              either from the try body or the catch body.
*/
template<class EXCEPTION = std::exception, class TRY_BLOCK, class CATCH_BLOCK, class FINALLY_BLOCK>
inline void TryFinally(TRY_BLOCK ___try, CATCH_BLOCK ___catch, FINALLY_BLOCK ___finally)
{
    try
    {
        ___try();
    }
    catch (EXCEPTION& e)
    {
        try
        {
            ___catch(e);
        }
        catch (...)
        {
            ___finally();
            throw;
        }
    }
    catch (...)
    {
        ___finally();
        throw;
    }
    ___finally();
}

#endif // !_TRY_CACTH_FINALLY_

