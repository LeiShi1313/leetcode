//
// Created by Dicky Shi on 6/13/17.
//

#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#endif //PROJECT_UTILS_H


template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

template<typename T>
void printVectorInVector(const T& t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}

template<typename T1>
std::ostream& operator <<( std::ostream& out, const std::vector<T1>& object )
{
    out << "[";
    if ( !object.empty() )
    {
        //std::copy( object.begin(), --object.end(), std::ostream_iterator<T1>( out, ", " ) );
        for(typename std::vector<T1>::const_iterator t = object.begin(); t != object.end() - 1; ++t) {
            out << *t << ", ";
        }
        out << *--object.end(); // print the last element separately to avoid the extra characters following it.
    }
    out << "]";
    return out;
}