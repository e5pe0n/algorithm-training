package _scala

import scala.collection.mutable.ArrayBuffer
import scala.io.Source
import scala.collection.mutable.Queue

object Main_04_07_v01 extends App {
  class Edge(val u: Int, val v: Int) {
    var used = false
  }

  def getBuildOrder(n: Int, graph: Array[ArrayBuffer[Int]], edges: Array[Edge]): Array[Int] = {
    val buildOrder = new Array[Int](n).map(_ => -1)
    var ord = 0
    for (i <- 0 until n) {
      val q = new Queue[Int]
      q += i
      while (q.nonEmpty) {
        val u = q.dequeue()
        if (buildOrder(u) < 0) {
          val notBuildable = graph(u) exists (x => edges(x).v == u && !edges(x).used)
          if (!notBuildable) {
            buildOrder(u) = ord
            ord += 1
            graph(u).foreach(x =>
              if (edges(x).u == u) {
                edges(x).used = true
                q += edges(x).v
              }
            )
          }
        }
      }
    }
    val res = new Array[Int](n)
    for (i <- 0 until n) {
      if (buildOrder(i) < 0) return new Array[Int](0)
      res(buildOrder(i)) = i
    }
    res
  }

  def solve(fp: String): Unit = {
    println(f"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val Array(n, m) = lines.next().split(' ').map(x => x.toInt)
    val graph = new Array[ArrayBuffer[Int]](n).map(_ => new ArrayBuffer[Int])
    val edges = new Array[Edge](m)
    for (i <- 0 until m) {
      val Array(u, v) = lines.next().split(' ').map(x => x.toInt - 1)
      edges(i) = new Edge(u, v)
      graph(u) += i
      graph(v) += i
    }
    val res = getBuildOrder(n, graph, edges)
    println(if (res.size > 0) res.map(x => (x + 1).toString).mkString(" ") else "error")
    println()
  }

  solve("../testcases/04_07/01.txt")
  solve("../testcases/04_07/02.txt")
  solve("../testcases/04_07/03.txt")
  solve("../testcases/04_07/04.txt")
  solve("../testcases/04_07/05.txt")
  solve("../testcases/04_07/06.txt")
}

// # ../testcases/04_07/01.txt
// 5 6 2 1 4 3

// # ../testcases/04_07/02.txt
// error

// # ../testcases/04_07/03.txt
// 2 1 3 5 12 9 8 4 7 6 10 11

// # ../testcases/04_07/04.txt
// error

// # ../testcases/04_07/05.txt
// 1 2

// # ../testcases/04_07/06.txt
// error
