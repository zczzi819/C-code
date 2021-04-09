#pragma once

namespace bit
{
	template<class T>
	struct __list_node
	{
		T _data;
		__list_node<T>* _next;
		__list_node<T>* _prev;

		__list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	// <T, T&, T*> iterator
	// <T, const T&, const T*> const_iterator
	// 类设计的复用
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _node;

		__list_node(node* node)
			:_node(node)
		{}

		// 拷贝构造 赋值重载 析构都不用实现，默认就可以

		bool operator!=(const self& s) const
		{
			return _node != self._node;
		}

		bool operator==(const self& s) const
		{
			return !(*this != s)
		}

		// operator->

		Ref operator*()
		{
			return _node->_data;
		}

		// ++it
		self operator++(int);
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator--(int);
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;


		iterator begin()
		{
			return _head->_next;
			//return iterator(_head->_next);
			//iterator it(_head->_next);
			//return it;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
			//return iterator(_head->_next);
			//iterator it(_head->_next);
			//return it;
		}

		const_iterator end() const
		{
			return _head;
		}

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;
			// _head  ...  tail  newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		// 双向带头循环
		node* _head;
	};
}