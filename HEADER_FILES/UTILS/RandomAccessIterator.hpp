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
    class RandomAccessIterator {

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
        RandomAccessIterator() : _ptr(NULL) {};
        explicit RandomAccessIterator(pointer it) : _ptr(it) {};
        RandomAccessIterator(const RandomAccessIterator &it) { *this = it; };
        RandomAccessIterator &operator=(const RandomAccessIterator &rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~RandomAccessIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        reference operator*() { return (*_ptr); };

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        pointer operator->() { return (_ptr); };

        // --------------------------------------------- [] OPERATOR ---------------------------------------------------
        reference operator[](const difference_type &off) { return (_ptr[off]); };

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        RandomAccessIterator &operator++() {_ptr++; return (*this);};

        RandomAccessIterator operator++(int) {
            RandomAccessIterator temp(*this);

            _ptr++;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        RandomAccessIterator &operator--() {_ptr--; return (*this);};

        RandomAccessIterator operator--(int) {
            RandomAccessIterator temp(*this);

            _ptr--;
            return (temp);
        };

        // ----------------------------------------- ARITHMETIC OPERATORS  ---------------------------------------------
        difference_type operator+(const RandomAccessIterator<T> &rhs) { return (_ptr + rhs._ptr); };

        RandomAccessIterator operator+(const difference_type &off) { return RandomAccessIterator<T>(_ptr + off); };

        difference_type operator-(const RandomAccessIterator<T> &rhs) { return (_ptr - rhs._ptr); };

        RandomAccessIterator operator-(const difference_type &off) { return RandomAccessIterator<T>(_ptr - off); };

        RandomAccessIterator &operator+=(const difference_type &off) {
            _ptr += off;
            return (*this);
        };

        RandomAccessIterator &operator-=(const difference_type &off) {
            _ptr -= off;
            return (*this);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        template<typename T2>
        friend bool operator<(const RandomAccessIterator<T2> &lhs,
                              const RandomAccessIterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); };

        template<typename T2>
        friend bool operator>(const RandomAccessIterator<T2> &lhs,
                              const RandomAccessIterator<T2> &rhs) { return (rhs < lhs);};

        template<typename T2>
        friend bool operator<=(const RandomAccessIterator<T2> &lhs,
                               const RandomAccessIterator<T2> &rhs) { return !(rhs < lhs); };

        template<typename T2>
        friend bool operator>=(const RandomAccessIterator<T2> &lhs,
                               const RandomAccessIterator<T2> &rhs) { return !(lhs < rhs); };

        template<typename T2>
        friend bool operator==(const RandomAccessIterator<T2> &lhs,
                               const RandomAccessIterator<T2> &rhs) { return (lhs._ptr == rhs._ptr); };

        template<typename T2>
        friend bool operator!=(const RandomAccessIterator<T2> &lhs,
                               const RandomAccessIterator<T2> &rhs) { return !(lhs == rhs); };

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
        ConstRandomAccesIterator(const ConstRandomAccesIterator &it) {*this = it;};
        ConstRandomAccesIterator(const RandomAccessIterator<T> &it) { _ptr = it.get_ptr();};
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
            ConstRandomAccesIterator temp(*this);

            _ptr++;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstRandomAccesIterator &operator--() { _ptr--; return (*this);};

        ConstRandomAccesIterator operator--(int) {
            ConstRandomAccesIterator temp(*this);

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
        template<typename T2>
        friend bool operator<(const ConstRandomAccesIterator<T2> &lhs,
                              const ConstRandomAccesIterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); };

        template<typename T2>
        friend bool operator>(const ConstRandomAccesIterator<T2> &lhs,
                              const ConstRandomAccesIterator<T2> &rhs) { return (rhs < lhs);};

        template<typename T2>
        friend bool operator<=(const ConstRandomAccesIterator<T2> &lhs,
                               const ConstRandomAccesIterator<T2> &rhs) { return !(rhs < lhs); };

        template<typename T2>
        friend bool operator>=(const ConstRandomAccesIterator<T2> &lhs,
                               const ConstRandomAccesIterator<T2> &rhs) { return !(lhs < rhs); };

        template<typename T2>
        friend bool operator==(const ConstRandomAccesIterator<T2> &lhs,
                               const ConstRandomAccesIterator<T2> &rhs) { return (lhs._ptr == rhs._ptr); };

        template<typename T2>
        friend bool operator!=(const ConstRandomAccesIterator<T2> &lhs,
                               const ConstRandomAccesIterator<T2> &rhs) { return !(lhs == rhs); };

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
        RevRandomAccesIterator(const RevRandomAccesIterator &it) { *this = it; };
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
            RevRandomAccesIterator temp(*this);

            _ptr--;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        RevRandomAccesIterator &operator--() {_ptr++; return (*this);};

        RevRandomAccesIterator operator--(int) {
            RevRandomAccesIterator temp(*this);

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
        template<typename T2>
        friend bool operator<(const RevRandomAccesIterator<T2> &lhs,
                              const RevRandomAccesIterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); };

        template<typename T2>
        friend bool operator>(const RevRandomAccesIterator<T2> &lhs,
                              const RevRandomAccesIterator<T2> &rhs) { return (rhs < lhs);};

        template<typename T2>
        friend bool operator<=(const RevRandomAccesIterator<T2> &lhs,
                               const RevRandomAccesIterator<T2> &rhs) { return !(rhs < lhs); };

        template<typename T2>
        friend bool operator>=(const RevRandomAccesIterator<T2> &lhs,
                               const RevRandomAccesIterator<T2> &rhs) { return !(lhs < rhs); };

        template<typename T2>
        friend bool operator==(const RevRandomAccesIterator<T2> &lhs,
                               const RevRandomAccesIterator<T2> &rhs) { return (lhs._ptr == rhs._ptr); };

        template<typename T2>
        friend bool operator!=(const RevRandomAccesIterator<T2> &lhs,
                               const RevRandomAccesIterator<T2> &rhs) { return !(lhs == rhs); };

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
        ConstRevRandomAccesIterator(const ConstRevRandomAccesIterator &it) { *this = it; };
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
            ConstRevRandomAccesIterator temp(*this);

            _ptr--;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstRevRandomAccesIterator &operator--() {_ptr++; return (*this);};

        ConstRevRandomAccesIterator operator--(int) {
            ConstRevRandomAccesIterator temp(*this);

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
        template<typename T2>
        friend bool operator<(const ConstRevRandomAccesIterator<T2> &lhs,
                              const ConstRevRandomAccesIterator<T2> &rhs) { return (lhs._ptr < rhs._ptr); };

        template<typename T2>
        friend bool operator>(const ConstRevRandomAccesIterator<T2> &lhs,
                              const ConstRevRandomAccesIterator<T2> &rhs) { return (rhs < lhs);};

        template<typename T2>
        friend bool operator<=(const ConstRevRandomAccesIterator<T2> &lhs,
                               const ConstRevRandomAccesIterator<T2> &rhs) { return !(rhs < lhs); };

        template<typename T2>
        friend bool operator>=(const ConstRevRandomAccesIterator<T2> &lhs,
                               const ConstRevRandomAccesIterator<T2> &rhs) { return !(lhs < rhs); };

        template<typename T2>
        friend bool operator==(const ConstRevRandomAccesIterator<T2> &lhs,
                               const ConstRevRandomAccesIterator<T2> &rhs) { return (lhs._ptr == rhs._ptr); };

        template<typename T2>
        friend bool operator!=(const ConstRevRandomAccesIterator<T2> &lhs,
                               const ConstRevRandomAccesIterator<T2> &rhs) { return !(lhs == rhs); };

    };

};

#endif //FT_CONTAINERS_RANDOMACCESITERATOR_HPP
