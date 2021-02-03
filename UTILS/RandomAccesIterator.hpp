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
        explicit RandomAccesIterator(pointer it) : _ptr(it) {};
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
        reference operator[](const difference_type &off) { return (_ptr[off]); };

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        RandomAccesIterator &operator++() {_ptr++; return (*this);};

        RandomAccesIterator operator++(int) {
            RandomAccesIterator<T> temp(*this);

            _ptr++;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        RandomAccesIterator &operator--() {_ptr--; return (*this);};

        RandomAccesIterator operator--(int) {
            RandomAccesIterator<T> temp(*this);

            _ptr--;
            return (temp);
        };

        // ----------------------------------------- ARITHMETIC OPERATORS  ---------------------------------------------
        difference_type operator+(const RandomAccesIterator<T> &rhs) { return (_ptr + rhs._ptr); };

        RandomAccesIterator operator+(const difference_type &off) { return RandomAccesIterator<T>(_ptr + off); };

        difference_type operator-(const RandomAccesIterator<T> &rhs) { return (_ptr - rhs._ptr); };

        RandomAccesIterator operator-(const difference_type &off) { return RandomAccesIterator<T>(_ptr - off); };

        RandomAccesIterator &operator+=(const difference_type &off) {
            _ptr += off;
            return (*this);
        };

        RandomAccesIterator &operator-=(const difference_type &off) {
            _ptr -= off;
            return (*this);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator<(const RandomAccesIterator<T> &rhs) { return (_ptr < rhs._ptr); };

        bool operator>(const RandomAccesIterator<T> &rhs) { return (_ptr > rhs._ptr); };

        bool operator<=(const RandomAccesIterator<T> &rhs) { return (_ptr <= rhs._ptr); };

        bool operator>=(const RandomAccesIterator<T> &rhs) { return (_ptr >= rhs._ptr); };

        bool operator==(const RandomAccesIterator<T> &rhs) { return (_ptr == rhs._ptr); };

        template<class Iterator>
        bool operator!=(const RandomAccesIterator<T> &rhs) { return (_ptr != rhs._ptr); };

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const pointer &get_ptr() const { return (_ptr); };
    };


    template<typename T>
    class ConstRandomAccesIterator {

    public:
        // MEMBER TYPES
        typedef std::random_access_iterator_tag     iterator_category;
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   *pointer;
        typedef T                                   &reference;
        typedef const T                             *const_pointer;
        typedef const T                             &const_reference;

    private:
        pointer _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        ConstRandomAccesIterator() : _ptr(NULL) {};
        explicit ConstRandomAccesIterator(pointer it)  : _ptr(it) {};
        ConstRandomAccesIterator(const ConstRandomAccesIterator<T> &it) {*this = it;};
        ConstRandomAccesIterator(const RandomAccesIterator<T> &it) {_ptr = it.get_ptr();};
        ConstRandomAccesIterator &operator=(const ConstRandomAccesIterator &rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~ConstRandomAccesIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        const_reference operator*() { return (*_ptr); };

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        const_pointer operator->() { return (_ptr); };

        // --------------------------------------------- [] OPERATOR ---------------------------------------------------
        const_reference operator[](const difference_type &off) {return (_ptr[off]);};

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        ConstRandomAccesIterator &operator++() { _ptr++; return (*this);};

        ConstRandomAccesIterator operator++(int) {
            ConstRandomAccesIterator<T> temp(*this);

            _ptr++;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstRandomAccesIterator &operator--() { _ptr--; return (*this);};

        ConstRandomAccesIterator operator--(int) {
            ConstRandomAccesIterator<T> temp(*this);

            _ptr--;
            return (temp);
        };

        // ----------------------------------------- ARITHMETIC OPERATORS  ---------------------------------------------
        difference_type operator+(const ConstRandomAccesIterator<T> &rhs) {return (_ptr + rhs._ptr);};

        ConstRandomAccesIterator operator+(const difference_type &off) {return ConstRandomAccesIterator<T>(_ptr + off);};

        difference_type operator-(const ConstRandomAccesIterator<T> &rhs) {return (_ptr - rhs._ptr);};

        ConstRandomAccesIterator operator-(const difference_type &off) {return ConstRandomAccesIterator<T>(_ptr - off);};

        ConstRandomAccesIterator &operator+=(const difference_type &off) {_ptr += off; return (*this);};

        ConstRandomAccesIterator &operator-=(const difference_type &off) {_ptr -= off; return (*this);};

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator<(const ConstRandomAccesIterator<T> &rhs) {return (_ptr < rhs._ptr);};

        bool operator>(const ConstRandomAccesIterator<T> &rhs) {return (_ptr > rhs._ptr);};

        bool operator<=(const ConstRandomAccesIterator<T> &rhs) {return (_ptr <= rhs._ptr);};

        bool operator>=(const ConstRandomAccesIterator<T> &rhs) {return (_ptr >= rhs._ptr);};

        bool operator==(const ConstRandomAccesIterator<T> &rhs) {return (_ptr == rhs._ptr);};

        template<class Iterator>
        bool operator!=(const ConstRandomAccesIterator<T> &rhs) {return (_ptr != rhs._ptr);};

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const pointer &get_ptr() const { return (_ptr); };
    };


    template<typename T>
    class RevRandomAccesIterator {

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
        RevRandomAccesIterator() : _ptr(NULL) {};
        explicit RevRandomAccesIterator(pointer it) : _ptr(it) {};
        RevRandomAccesIterator(const RevRandomAccesIterator<T> &it) { *this = it; };
        RevRandomAccesIterator &operator=(const RevRandomAccesIterator &rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~RevRandomAccesIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        reference operator*() { return (*_ptr); };

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        pointer operator->() { return (_ptr); };

        // --------------------------------------------- [] OPERATOR ---------------------------------------------------
        reference operator[](const difference_type &off) { return (_ptr[-off]); };

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        RevRandomAccesIterator &operator++() {_ptr--; return (*this);};

        RevRandomAccesIterator operator++(int) {
            RevRandomAccesIterator<T> temp(*this);

            _ptr--;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        RevRandomAccesIterator &operator--() {_ptr++; return (*this);};

        RevRandomAccesIterator operator--(int) {
            RevRandomAccesIterator<T> temp(*this);

            _ptr++;
            return (temp);
        };

        // ----------------------------------------- ARITHMETIC OPERATORS  ---------------------------------------------
        difference_type operator+(const RevRandomAccesIterator<T> &rhs) { return (_ptr - rhs._ptr); };

        RevRandomAccesIterator operator+(const difference_type &off) { return RevRandomAccesIterator<T>(_ptr - off); };

        difference_type operator-(const RevRandomAccesIterator<T> &rhs) { return (_ptr + rhs._ptr); };

        RevRandomAccesIterator operator-(const difference_type &off) { return RevRandomAccesIterator<T>(_ptr + off); };

        RevRandomAccesIterator &operator+=(const difference_type &off) {
            _ptr -= off;
            return (*this);
        };

        RevRandomAccesIterator &operator-=(const difference_type &off) {
            _ptr += off;
            return (*this);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator<(const RevRandomAccesIterator<T> &rhs) { return (_ptr < rhs._ptr); };

        bool operator>(const RevRandomAccesIterator<T> &rhs) { return (_ptr > rhs._ptr); };

        bool operator<=(const RevRandomAccesIterator<T> &rhs) { return (_ptr <= rhs._ptr); };

        bool operator>=(const RevRandomAccesIterator<T> &rhs) { return (_ptr >= rhs._ptr); };

        bool operator==(const RevRandomAccesIterator<T> &rhs) { return (_ptr == rhs._ptr); };

        template<class Iterator>
        bool operator!=(const RevRandomAccesIterator<T> &rhs) { return (_ptr != rhs._ptr); };

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const pointer &get_ptr() const { return (_ptr); };
    };


    template<typename T>
    class ConstRevRandomAccesIterator {

    public:
        // MEMBER TYPES
        typedef std::random_access_iterator_tag     iterator_category;
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   *pointer;
        typedef T                                   &reference;
        typedef const T                             *const_pointer;
        typedef const T                             &const_reference;

    private:
        pointer _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        ConstRevRandomAccesIterator() : _ptr(NULL) {};
        explicit ConstRevRandomAccesIterator(pointer it) : _ptr(it) {};
        ConstRevRandomAccesIterator(const ConstRevRandomAccesIterator<T> &it) { *this = it; };
        ConstRevRandomAccesIterator(const RevRandomAccesIterator<T> &it) {_ptr = it.get_ptr();};
        ConstRevRandomAccesIterator &operator=(const ConstRevRandomAccesIterator &rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~ConstRevRandomAccesIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        const_reference operator*() { return (*_ptr); };

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        const_pointer operator->() { return (_ptr); };

        // --------------------------------------------- [] OPERATOR ---------------------------------------------------
        const_reference operator[](const difference_type &off) { return (_ptr[-off]); };

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        ConstRevRandomAccesIterator &operator++() {_ptr--; return (*this);};

        ConstRevRandomAccesIterator operator++(int) {
            ConstRevRandomAccesIterator<T> temp(*this);

            _ptr--;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstRevRandomAccesIterator &operator--() {_ptr++; return (*this);};

        ConstRevRandomAccesIterator operator--(int) {
            ConstRevRandomAccesIterator<T> temp(*this);

            _ptr++;
            return (temp);
        };

        // ----------------------------------------- ARITHMETIC OPERATORS  ---------------------------------------------
        difference_type operator+(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr - rhs._ptr); };

        ConstRevRandomAccesIterator operator+(const difference_type &off) { return ConstRevRandomAccesIterator<T>(_ptr - off); };

        difference_type operator-(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr + rhs._ptr); };

        ConstRevRandomAccesIterator operator-(const difference_type &off) { return ConstRevRandomAccesIterator<T>(_ptr + off); };

        ConstRevRandomAccesIterator &operator+=(const difference_type &off) {
            _ptr -= off;
            return (*this);
        };

        ConstRevRandomAccesIterator &operator-=(const difference_type &off) {
            _ptr += off;
            return (*this);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator<(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr < rhs._ptr); };

        bool operator>(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr > rhs._ptr); };

        bool operator<=(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr <= rhs._ptr); };

        bool operator>=(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr >= rhs._ptr); };

        bool operator==(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr == rhs._ptr); };

        template<class Iterator>
        bool operator!=(const ConstRevRandomAccesIterator<T> &rhs) { return (_ptr != rhs._ptr); };

    };

};

#endif //FT_CONTAINERS_RANDOMACCESITERATOR_HPP
