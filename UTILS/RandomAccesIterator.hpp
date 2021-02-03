/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccesIterator.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 15:50:16 by roybakker     #+#    #+#                 */
/*   Updated: 2021/02/02 15:50:16 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESITERATOR_HPP
#define RANDOMACCESITERATOR_HPP

namespace ft {

    template<typename T>
    class RandomAccesIterator {

    public:
        // MEMBER TYPES
        typedef std::random_access_iterator_tag     iterator_category;
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   *pointer;
        typedef T                                   &reference;

    private:
        pointer _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        RandomAccesIterator() : _ptr(NULL) {};

        explicit RandomAccesIterator(pointer it)  : _ptr(it) {};

        RandomAccesIterator(const RandomAccesIterator<T> &it) { *this = it; };

        RandomAccesIterator &operator=(const RandomAccesIterator &rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~RandomAccesIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        reference operator*() { return (*_ptr); };

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        pointer operator->() { return (_ptr); };

        // --------------------------------------------- [] OPERATOR ---------------------------------------------------
        reference operator[](const difference_type &off) {return (_ptr[off]);};

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        RandomAccesIterator &operator++() { _ptr++; return (*this);};

        RandomAccesIterator operator++(int) { //postfix
            RandomAccesIterator<T> temp(*this);

            _ptr++;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        RandomAccesIterator &operator--() { _ptr--; return (*this);};

        RandomAccesIterator operator--(int) { //postfix
            RandomAccesIterator<T> temp(*this);

            _ptr--;
            return (temp);
        };

        // ----------------------------------------- ARITHMETIC OPERATORS  ---------------------------------------------
        difference_type operator+(const RandomAccesIterator<value_type> &rhs) {return (_ptr + rhs._ptr);};

        RandomAccesIterator operator+(const difference_type &off) {return RandomAccesIterator<T>(_ptr + off);};

        difference_type operator-(const RandomAccesIterator<value_type> &rhs) {return (_ptr - rhs._ptr);};

        RandomAccesIterator operator-(const difference_type &off) {return RandomAccesIterator(_ptr - off);};

        RandomAccesIterator &operator+=(const difference_type &off) {_ptr += off; return (*this);};

        RandomAccesIterator &operator-=(const difference_type &off) {_ptr -= off; return (*this);};

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator<(const RandomAccesIterator<value_type> &rhs) {return (_ptr < rhs._ptr);};

        bool operator>(const RandomAccesIterator<value_type> &rhs) {return (_ptr > rhs._ptr);};

        bool operator<=(const RandomAccesIterator<value_type> &rhs) {return (_ptr <= rhs._ptr);};

        bool operator>=(const RandomAccesIterator<value_type> &rhs) {return (_ptr >= rhs._ptr);};

        bool operator==(const RandomAccesIterator<value_type> &rhs) {return (_ptr == rhs._ptr);};

        template<class Iterator>
        bool operator!=(const RandomAccesIterator<value_type> &rhs) {return (_ptr != rhs._ptr);};

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const pointer &get_ptr() const { return (_ptr); };
    };
};

#endif //FT_CONTAINERS_RANDOMACCESITERATOR_HPP
