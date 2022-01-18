/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:48:02 by gozsertt          #+#    #+#             */
/*   Updated: 2022/01/18 15:57:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP


namespace ft {

enum _Rb_tree_color {
	
	_S_red = false,
	_S_black = true
};

struct _Rb_tree_node_base {

	typedef _Rb_tree_node_base* _Base_ptr;
	typedef const _Rb_tree_node_base* _Const_Base_ptr;

	_Rb_tree_color			_M_color;
	_Base_ptr				_M_parent;
	_Base_ptr				_M_left;
	_Base_ptr				_M_right;

	static _Base_ptr
	_S_minimum(_Base_ptr __x) _GLIBCXX_NOEXCEPT
	{
		while (__x->_M_left != 0) __x = __x->_M_left;
		return __x;
	}
	static _Const_Base_ptr
	_S_minimum(_Const_Base_ptr __x) _GLIBCXX_NOEXCEPT
	{
		while (__x->_M_left != 0) __x = __x->_M_left;
		return __x;
	}
	static _Base_ptr
	_S_maximum(_Base_ptr __x) _GLIBCXX_NOEXCEPT
	{
		while (__x->_M_right != 0) __x = __x->_M_right;
		return __x;
	}
	static _Const_Base_ptr
	_S_maximum(_Const_Base_ptr __x) _GLIBCXX_NOEXCEPT
	{
		while (__x->_M_right != 0) __x = __x->_M_right;
		return __x;
	}
};

  // Helper type offering value initialization guarantee on the compare functor.
  template<typename _Key_compare>
	struct _Rb_tree_key_compare
	{
	  _Key_compare                _M_key_compare;
	  _Rb_tree_key_compare()
	  _GLIBCXX_NOEXCEPT_IF(
		is_nothrow_default_constructible<_Key_compare>::value)
	  : _M_key_compare()
	  { }
	  _Rb_tree_key_compare(const _Key_compare& __comp)
	  : _M_key_compare(__comp)
	  { }
#if __cplusplus >= 201103L
	  // Copy constructor added for consistency with C++98 mode.
	  _Rb_tree_key_compare(const _Rb_tree_key_compare&) = default;
	  _Rb_tree_key_compare(_Rb_tree_key_compare&& __x)
		noexcept(is_nothrow_copy_constructible<_Key_compare>::value)
	  : _M_key_compare(__x._M_key_compare)
	  { }
#endif
};


};

#endif