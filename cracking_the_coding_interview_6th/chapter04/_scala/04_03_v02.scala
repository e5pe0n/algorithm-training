package _scala

import scala.io.Source
import scala.collection.mutable.{ArrayBuffer, Queue}

object Main_04_03_v02 extends App {
  case class Node(val x: Int, val left: Node = null, val right: Node = null) {
    override def toString(): String = s"($left $x $right)"
  }

  class Tree(val root: Node) {
    override def toString(): String = root.toString()
  }

  def rec(v: Array[Int], left: Int, right: Int): Node = (right - left) match {
    case 0 => null
    case 1 => new Node(v(left))
    case _ => {
      val mid = (left + right) / 2
      val lc = rec(v, left, mid)
      val rc = rec(v, mid + 1, right)

      new Node(v(mid), lc, rc)
    }
  }

  def makeMinBST(v: Array[Int]): Tree = new Tree(rec(v, 0, v.size))

  def makeDepthTree(tree: Tree): ArrayBuffer[ArrayBuffer[Node]] = {
    var res = new ArrayBuffer[ArrayBuffer[Node]]
    if (tree.root == null) return res

    res += new ArrayBuffer[Node]
    res(0) += tree.root
    var q = new Queue[Tuple2[Node, Int]]
    q += ((tree.root, 0))
    while (!q.isEmpty) {
      val (par, depth) = q.dequeue()
      if (res.size <= depth + 1) res += new ArrayBuffer[Node]
      if (par.left != null) {
        res(depth + 1) += par.left
        q += ((par.left, depth + 1))
      }
      if (par.right != null) {
        res(depth + 1) += par.right
        q += ((par.right, depth + 1))
      }
    }

    res.filter(x => x.size > 0)
  }

  def showList(v: ArrayBuffer[ArrayBuffer[Node]]): Unit = {
    for (i <- 0 until v.size) {
      println(f"$i: ${v(i).map(n => n.x).mkString(" ")}")
    }
  }

  def solve(fp: String): Unit = {
    val lines = Source.fromFile(fp).getLines()
    lines.next()
    println(f"# $fp")
    val v = lines.next().split(' ').map(x => x.toInt)
    val tree = makeMinBST(v)
    val res = makeDepthTree(tree)
    showList(res)
    println
  }

  solve("../testcases/04_03/01.txt")
  solve("../testcases/04_03/02.txt")
  solve("../testcases/04_03/03.txt")
  solve("../testcases/04_03/04.txt")
}

// # ../testcases/04_03/01.txt
// 0: 4
// 1: 2 6
// 2: 1 3 5 7

// # ../testcases/04_03/02.txt
// 0: 5
// 1: 3 7
// 2: 2 4 6 8
// 3: 1

// # ../testcases/04_03/03.txt
// 0: 6
// 1: 3 9
// 2: 2 5 8 10
// 3: 1 4 7

// # ../testcases/04_03/04.txt
// 0: 2
// 1: 1
