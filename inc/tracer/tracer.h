/**
 * @file tracer.h
 * @author tang anke
 * @brief head-only variable tracer
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <list>

template <typename T>
class tracer {
  T m_data;
  std::list<T> m_history;

 public:
  tracer() = default;
  explicit tracer(const T& data)
      : m_data(data) { }

  std::list<T>& history() { return m_history; }
  const std::list<T>& history() const { return m_history; }

  void clear_history() { m_history.clear(); }
  void mark() { m_history.push_back(m_data); }
  void mark(const T& data) {
    m_data = data;
    m_history.push_back(m_data); // inline mark();
  }

  void operator=(const T& data) { m_data = data; }

  operator T() const { return m_data; }
};

template <typename T>
class auto_tracer {
  T m_data;
  std::list<T> m_history;

 public:
  auto_tracer() = default;
  explicit auto_tracer(const T& data)
      : m_data(data) { m_history.push_back(m_data); }

  std::list<T>& history() { return m_history; }
  const std::list<T>& history() const { return m_history; }

  void clear_history() { m_history.clear(); }

  void operator=(const T& data) {
    m_data = data;
    m_history.push_back(m_data); // mark
  }

  /**
   * @brief set data, without history marking
   */
  auto_tracer& set(const T& data) {
    m_data = data;
    return *this;
  }

  operator T() const { return m_data; }
};
