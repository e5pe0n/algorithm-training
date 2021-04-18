// Cracking the Coding Interview p.234
package scala

import scala.collection.mutable.ArrayBuffer

class Node(val value: Int) {
  var above: Option[Node] = None
  var below: Option[Node] = None
}

class Stack(private val capacity: Int) {
  var top: Option[Node] = None
  var btm: Option[Node] = None
  var size: Int = 0

  def isFull(): Boolean = size == capacity
  def isEmpty(): Boolean = size == 0
  def join(above: Option[Node], below: Option[Node]): Unit = {
    below match {
      case Some(node) => node.above = above
      case None       =>
    }
    above match {
      case Some(node) => node.below = below
      case None       =>
    }
  }

  def push(x: Int): Boolean = {
    if (size >= capacity) return false
    size += 1
    val n = Option(new Node(x))
    if (size == 1) btm = n
    join(n, top)
    top = n

    true
  }

  def pop(): Int =
    top match {
      case Some(node) => {
        top = node.below

        node.value
      }
      case None => throw new EmptyStackException
    }

  def rm_btm(): Int =
    btm match {
      case None => throw new EmptyStackException
      case Some(node) => {
        btm = node.above
        btm match {
          case Some(n) => n.below = Option(None)
          case None    =>
        }
        size -= 1

        node.value
      }
    }
}

class SetOfStack(val capacity: Int) {
  val stacks: ArrayBuffer[Stack] = Nil

  def lastStack: Option[Stack] =
    if (stacks.isEmpty) None else stacks(stacks.length - 1)

  def push(x: Int): Unit =
    if (!lastStack.isEmpty && !lastStack.get.isFull) {
      lastStack.get.push(x)
    } else {
      val stack = new Stack(capacity)
      stack.push(x)
      stacks += stack
    }

  def pop(): Int =
    lastStack match {
      case None => throw new EmptyStackException
      case Some(node) => {
        val x = node.pop()
        if (node.isEmpty) stacks.remove(stacks.length - 1)

        x
      }
    }

  def isEmpty(): Boolean = lastStack.isEmpty

  def popAt(idx: Int): Int = leftShift(idx, true)

  def leftShift(idx: Int, rmTop: Boolean): Int = {
    val stack = stacks(idx)
    val rmdTop = if (rmTop) stack.pop() else stack.rm_btm()
    if (stack.isEmpty) stacks.remove(stacks.length - 1)
    else if (stacks.length > idx + 1) {
      val x = leftShift(idx + 1, false)
      stack.push(x)
    }

    rmdTop
  }
}
