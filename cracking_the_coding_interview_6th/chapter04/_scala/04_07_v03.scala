package _scala

import scala.collection.Iterable
import scala.collection.mutable.{Map, ArrayBuffer}
import scala.io.Source

object Main_04_07_v03 extends App {
  class Project(private val _name: Int) {
    private var _dependencies = 0
    private val _children: Map[Int, Project] = Map[Int, Project]()

    def name: Int = _name
    def dependencies: Int = _dependencies
    def children: Iterable[Project] = _children.values

    def addNeighbor(node: Project) {
      if (!(_children contains node.name)) {
        _children += (node.name -> node)
        node.incrementDependencies()
      }
    }

    def incrementDependencies(): Unit = _dependencies += 1
    def decrementDependencies(): Unit = _dependencies -= 1
  }

  class Graph {
    private val _nodes: Map[Int, Project] = Map[Int, Project]()

    def nodes: Iterable[Project] = _nodes.values
    def getOrCreateNode(name: Int): Project = {
      if (!(_nodes contains name)) _nodes += (name -> new Project(name))
      _nodes(name)
    }
    def addEdge(startName: Int, endName: Int): Unit = {
      val start = getOrCreateNode(startName)
      val end = getOrCreateNode(endName)
      start.addNeighbor(end)
    }
  }

  def addNonDependent(order: Array[Project], projects: Iterable[Project], offset: Int): Int = {
    var res = offset
    projects.foreach(x =>
      if (x.dependencies == 0) {
        order(res) = x
        res += 1
      }
    )
    res
  }

  def orderProject(projects: Iterable[Project]): Array[Project] = {
    val order: Array[Project] = new Array[Project](projects.size)
    var endOfList = addNonDependent(order, projects, 0)
    var toBeProcessed = 0
    while (toBeProcessed < order.size) {
      val current = order(toBeProcessed)
      if (current == null) return new Array[Project](0)
      for (child <- current.children) child.decrementDependencies()
      endOfList = addNonDependent(order, current.children, endOfList)
      toBeProcessed += 1
    }
    order
  }

  def solve(fp: String): Unit = {
    println(s"# $fp")
    val lines = Source.fromFile(fp).getLines()
    val Array(n, m) = lines.next().split(' ').map(x => x.toInt)
    val graph = new Graph
    for (i <- 0 until n) graph.getOrCreateNode(i)
    for (_ <- 0 until m) {
      val Array(u, v) = lines.next().split(' ').map(x => x.toInt - 1)
      graph.addEdge(u, v)
    }
    val res = orderProject(graph.nodes)
    println(if (res.size > 0) res.map(x => (x.name + 1).toString).mkString(" ") else "error")
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
// 2 3 8 1 5 12 9 4 7 6 10 11

// # ../testcases/04_07/04.txt
// error

// # ../testcases/04_07/05.txt
// 1 2

// # ../testcases/04_07/06.txt
// error
