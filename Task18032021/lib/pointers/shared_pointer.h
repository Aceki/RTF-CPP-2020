#pragma once

#include <algorithm>

#include "counter.h"

namespace Pointers
{
	template<class T>
	class SharedPointer
	{
	public:
		SharedPointer() = default;

		SharedPointer(T* obj) : m_counter(new Counter<T>(obj)) { }

		SharedPointer(const SharedPointer<T>&);

		T* get() const { return isEmpty() ? nullptr : m_counter->pointer(); }

		int useCount() const { return isEmpty() ? 0 : m_counter->count(); }

		void swap(SharedPointer<T>&);

		T& operator*() const { return *(m_counter->pointer()); }

		T* operator->() const { return m_counter->pointer(); }

		bool operator==(const SharedPointer<T>& ptr) const { return m_counter == ptr.m_counter; }

		SharedPointer& operator=(const SharedPointer<T>&);

		operator bool() const { return m_counter != nullptr; }

		~SharedPointer();
	private:
		bool isEmpty() const { return m_counter == nullptr; }

		void share(const SharedPointer<T>&);

		Counter<T>* m_counter = nullptr;
	};

	template<class T>
	SharedPointer<T>::SharedPointer(const SharedPointer<T>& sptr)
	{
		if(!sptr.isEmpty())
			share(sptr);
	}

	template<class T>
	SharedPointer<T>::~SharedPointer()
	{
		if(useCount() > 1)
			m_counter->decrease();
		else
			delete m_counter;
	}

	template<class T>
	void SharedPointer<T>::swap(SharedPointer<T>& sptr)
	{
		std::swap(m_counter, sptr.m_counter);
	}

	template<class T>
	SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T>& sptr)
	{
		if(useCount() > 1)
			m_counter->decrease();
		else
			delete m_counter;
		
		share(sptr);
	}

	template<class T>
	void SharedPointer<T>::share(const SharedPointer<T>& sptr)
	{
		m_counter = sptr.m_counter;
		m_counter->increase();
	}
}