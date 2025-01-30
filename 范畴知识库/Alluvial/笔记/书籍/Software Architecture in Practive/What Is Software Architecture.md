# What is Software Architecture?

- 什么是软件架构？

  - 系统的软件架构是系统理应所需*（... needed to reason about ...，... 推理出 ... 的需要）*的一组结构。它包括了软件组成元素*（software elements）*、软件间的关系以及软件所拥有的属性*（properties）*。

    > The **software architecture** of a system **is the set of structures needed** to reason about the system, which comprise software elements, relations among them, and properties of both.

    - **Architecture Is a Set of Software Structures**：软件架构是软件结构的总集。

      第一类软件结构是软件中被分成实现单元的部分结构，我们称之为**模块** *（modules）*。

      第二类软件结构是软件运行时*（runtime）*，软件与其他部分进行交互的方式，通常称那些系统部分叫**服务**。书中会用**组件和连接器** *（component-and-connector, C&C）* 来称呼这种运行时的结构。

      第三类是在系统管理、开发、安装以及运行的环境下软件结构的映射。我们用**分配** *(allocation)* 来称呼这种结构。

      > First, some **structures partition systems into implementation units**, which in this book we call **<u>modules</u>**.
      >
      > Other structures are dynamic, meaning that they **focus on the way the elements interact with each other at runtime** to carry out the system’s functions. Suppose **the system is to be built as a set of <u>services</u>**. In this book we will **call runtime structures *<u>component-and-connector (C&C)</u>* structures**.
      >
      > A third kind of structure describes **the mapping from software structures** to the system’s organizational, developmental, installation, and execution environments. These mappings are called <u>***allocation***</u> structures.

- 架构的**结构（Structures）** 和 **视图（Views）**

  - **视图（Views）**：是一组连贯的体系结构元素的展示，通常由系统的利益相关者撰写和阅读。它通常包括了一些列元素和元素间关系的描述。

    > A view is a representation of a coherent set of architectural elements, as written by and read by system stakeholders. It consists of a representation of a set of elements and the relations among them.

  - **结构（Structures）**：是那些构成架构的元素本身。

    > A structure is the set of elements itself, as they exist in software or hardware.

    - 三种结构（Structures）：*在上面也有所描述*。

      1. 模块结构具体表现为一个软件系统是如何通过一系列代码、数据单元构成的。它允许我们回答这些问题：

         - 每个模块的主要**功能性职责**是什么？
         - 软件模块**允许使用**哪些软件内容？
         - 它实际**使用和依赖**的其他软件是什么？
         - 那些模块与其他模块有**泛化（generalization）或者特化（specialization）的关系**？

         > ***Module structures*** embody decisions as to how the system is to be structured as a set of code or data units that have to be constructed or procured. Module structures allow us to answer questions such as these:
         >
         > - What is the primary functional responsibility assigned to each module?
         > - What other software elements is a module allowed to use?
         > - What other software does it actually use and depend on?
         > - What modules are related to other modules by generalization or specialization (i.e., inheritance) relationships?

      2. 组件与连接器的结构可以帮助我们回答下面的问题：

         - 核心执行**组件是什么**以及它们如何在运行时**协同运作**？
         - 核心**数据存储器**是什么？
         - **复制**了系统的哪些部分？
         - **数据**在系统中是如何**处理**的？
         - 系统中的哪些部分能**并行处理**？
         - 系统的**结构能在运行时改变**吗？如果可以，是**如何改变**的？

         > ***Component-and-connector*** structures embody decisions as to how the system is to be structured as a set of elements that have runtime behavior (components) and interactions (connectors). Component-and-connector views help us answer questions such as these:
         >
         > - What are the major executing components and how do they interact at runtime?
         > - What are the major shared data stores?
         > - Which parts of the system are replicated?
         > - How does data progress through the system?
         > - What parts of the system can run in parallel?
         > - Can the system’s structure change as it executes and, if so, how?

      3. 分配结构具体表现为，系统是如何与那些非软件的结构发生关系的。它帮助我们回答这些问题：

         - 每个软件单元在哪个**处理器上执行**？
         - 在开发、测试和系统构建时，每个单元的**目录和文件**是什么？
         - 软件团队中每个**软件单元的分配**是什么样的？

         > ***Allocation structures*** embody decisions as to how the system will relate to nonsoftware structures in its environment (such as CPUs, file systems, networks, development teams, etc.). Allocation views help us answer questions such as these:
         >
         > - What processor does each software element execute on?
         > - In what directories or files is each element stored during development, testing, and system building?
         > - What is the assignment of each software element to development teams?

    - 一些很有用的模块结构（Module Structures）：

      - 分解结构，那些模块单元将会是其他模块的**子系统**，将模块递归的分解为尽可能小的模块，以方便我们去理解这个模块。

        > **Decomposition structure**. The units are modules that are related to each other by the **is-a-submodule-of relation**, showing how modules are decomposed into smaller modules recursively until the modules are small enough to be easily understood.

      - 使用结构，模块单元可能得从一个类去看待它。单元间有一种**"使用"**的关系，是一种特殊的依赖。

        > **Uses structure**. In this important but overlooked structure, the units here are also modules, perhaps classes. **The units are related by the uses relation,** a specialized form of dependency.

      - 层次结构，模块所属的结构被称为层次。一个层是一个抽象的虚拟机，它通过管理好的接口，提供了一系列完整的服务。

        > **Layer structure**. The modules in this structure are called layers. A layer is an abstract “virtual machine” that provides a cohesive set of services through a managed interface.

      - 类结构，类结构说明这个类的继承关系或者实例关系。

        > **Class (or generalization) structure**. The module units in this structure are called classes. The relation is inherits from or is an instance of.

      - 数据模块，数据模块对数据实体和他们之间的关系而言是一种静态的信息结构。

        > **Data model**. The data model describes the static information structure in terms of data entities and their relationships.

    - 一些很有用的组件-连接器结构（C&C Structures）：

      - 服务器结构，这里的单元是通过服务协调机制(如SOAP)彼此交互的。

        > **Service structure**. The units here are services that interoperate with each other by service coordination mechanisms such as SOAP (see Chapter 6).

      - 并发性结构，这个组件和连接器结构允许架构师确定并行处理的机会，并确定可能发生资源竞争的位置。

        > **Concurrency structure**. This component-and-connector structure allows the architect to determine opportunities for parallelism and the locations where resource contention may occur.

    - 一些很有用的分配结构（Allocation Structures）：

      - 部署结构，部署结构展示了软件是如何被分配到硬件进行处理以及元素通信。

        > **Deployment structure**. The deployment structure shows how software is assigned to hardware processing and communication elements.

      - 实现结构。这个结构显示了软件元素(通常是模块)是如何映射到系统开发、集成或配置控制环境中的文件结构的。

        > **Implementation structure**. This structure shows how software elements (usually modules) are mapped to the file structure(s) in the system’s development, integration, or configuration control environments.

      - 工作分配结构。该结构将实现和集成模块的责任分配给将执行该模块的团队。

        > **Work assignment structure**. This structure assigns responsibility for implementing and integrating the modules to the teams who will carry it out.

  - 架构模式（pattern）

    - 层模式（Layered pattern）：当“使用”关系在软件单元之间是严格单向的，一个系统层次就出现了。
    - 数据共享模式（Shared-data pattern）：这个模式包括了创建、存储以及访问持久化数据的组件和连结件。
    - 客户端-服务端模式（Client-server pattern）：组件是客户端和服务端，连接件是协议、他们分享的信息用来执行系统的工作。
    - 多层模式（Multi-tier pattern）：它描述了如何将一个系统的组件分发到不同的软件和硬件中，并通过某种中间件通信。
    - 能力中心和平台（Competence center and platform）：是将软件系统的工作分配结构专业化的模式。

  - 什么是好的架构？

    - 流程（process）上的建议：

      - 架构应该是一个由单个或者多个架构师与技术负责人的产品。这种方法给予架构本身概念的完整性以及技术的一致性。这一建议适用于敏捷、开源以及传统项目。**架构师和开发者团队必须保持紧密**，以避免不切实际的象牙塔设计（ivory tower designs）。

        > The architecture should be the product of a single architect or a small group of architects with an identified technical leader. This approach gives the architecture its conceptual integrity and technical consistency. This recommendation holds for Agile and open source projects as well as “traditional” ones. **There should be a strong connection between the architect(s) and the development team, to avoid ivory tower designs that are impractical.**

      - 一个渐进的基础上，架构师（或架构师团队）应该将架构建立在一个**有明确的质量参数需求列表**之上。这些将会了解那些经常发生的妥协。以及更少的功能性问题。

        > The architect (or architecture team) should, on an ongoing basis, **base the architecture on a prioritized list of well-specified quality attribute requirements**. These will inform the tradeoffs that always occur. Functionality matters less.

      - **架构应该用视图来记录**。视图应该解决那些最重要的利益相关者所关注的问题，以支持项目的时间线。这说明**最开始是一个精简的文档，而后在做详细说明**。关注的内容通常与构建、分析、系统维护以及对新相关者进行教育有关，

        > The architecture should be documented using **views**. The views should address the concerns of the most important stakeholders in support of the project timeline. **This might mean minimal documentation at first, elaborated later**. Concerns usually are related to construction, analysis, and maintenance of the system, as well as education of new stakeholders about the system.

      - 架构应该对它自己需要交付的**关键指标有所评估**。在软件生命周期的早期，这些就应该对他评估，或在有最大收益之后，合适的进行重复评估，**以确保体系结构不会过时**。

        > The architecture should **be evaluated for its ability to deliver the system’s important quality attributes**. This should occur early in the life cycle, when it returns the most benefit, and repeated as appropriate, to ensure that changes to the architecture (or the environment for which it is intended) **have not rendered the design obsolete**.

      - 体系应该有助于**增量实现**，以避免必须一次集成所有内容，这将有助于尽早发现问题。另一个办法是创建一个“骨架”系统，尽早的实现通信通路，尽管最开始只有很少功能。这个骨架系统可以用于增量地增长，并在必要时进行重构。

        > The architecture should **lend itself to incremental implementation**, to avoid having to integrate everything at once (which almost never works) as well as to discover problems early. One way to do this is to create a “skeletal” system in which the communication paths are exercised but which at first has minimal functionality. This skeletal system can be used to “grow” the system incrementally, refactoring as necessary.

    - 结构（structural）上的建议：

      - 体系结构应该具有**定义良好的模块**，这些模块的功能职责是根据**信息隐藏和关注点分离的原则分配**的。信息隐藏模块应该封装可能发生更改的内容，从而使软件免受这些更改的影响。每个模块都应该有一个定义良好的接口，对其他使用其工具的软件封装或“隐藏”可变方面。这些接口应该允许他们各自的开发团队在很大程度上相互独立地工作。

        > The architecture should **feature well-defined modules** whose functional **responsibilities are assigned on the principles of information hiding and separation of concerns**. The information-hiding modules should encapsulate things likely to change, thus insulating the software from the effects of those changes. Each module should have a well-defined interface that encapsulates or “hides” the changeable aspects from other software that uses its facilities. These interfaces should allow their respective development teams to work largely independently of each other.

      - 除非您的需求是前所未有的，否则您的质量指标应该使用**行业内最优实践**(在第13章中描述)。

        > Unless your requirements are unprecedented—possible, but unlikely—your quality attributes should **be achieved using well-known architectural patterns** and tactics (described in Chapter 13) specific to each attribute.

      - **体系结构不应该依赖于商业产品或工具的特定版本**。如果必须更改，则应该将其结构化，以便更改为不同的版本时既简单又便宜。

        > **The architecture should never depend on a particular version of a commercial product or tool**. If it must, it should be structured so that changing to a different version is straightforward and inexpensive.

      - **产生数据的模块应该与消费数据的模块分开**。这往往会增加可修改性，因为更改通常局限于数据的生产或消费方面。如果添加了新数据，则双方都必须更改，但这种分离允许分阶段(增量)升级。[生产者消费者模式](https://www.jdon.com/52885)

        > **Modules that produce data should be separate from modules that consume data**. This tends to increase modifiability because changes are frequently confined to either the production or the consumption side of data. If new data is added, both sides will have to change, but the separation allows for a staged (incremental) upgrade.

      - **不要期望模块和组件之间是一一对应的**。例如，在具有并发性的系统中，一个组件可能有多个并行运行的实例，其中每个组件都是从相同的模块构建的。对于具有多个并发线程的系统，每个线程可以使用来自多个组件的服务，每个组件都是由不同的模块构建的。

        > **Don’t expect a one-to-one correspondence between modules and components**. For example, in systems with concurrency, there may be multiple instances of a component running in parallel, where each component is built from the same module. For systems with multiple threads of concurrency, each thread may use services from several components, each of which was built from a different module.

      - **应该编写每个进程**，以便能够很容易地更改它对特定处理器的赋值，甚至可能在运行时更改。

        > **Every process should be written** so that its assignment to a specific processor can be easily changed, perhaps even at runtime.

      - **体系结构应该提供少量的组件交互方式**。也就是说，整个系统应该以相同的方式做相同的事情。这将有助于理解性、减少开发时间、增加可靠性和增强可修改性。

        > **The architecture should feature a small number of ways for components to interact.** That is, the system should do the same things in the same way throughout. This will aid in understandability, reduce development time, increase reliability, and enhance modifiability.

      - **体系结构应该包含一组特定的资源争用区域，该区域的解析是明确指定和维护的**。例如，如果网络利用率是一个需要关注的领域，那么架构师应该为每个开发团队制定能够产生最小网络流量的指导方针。如果考虑性能问题，架构师应该为主要线程制定时间预算。

        > **The architecture should contain a specific (and small) set of resource contention areas, the resolution of which is clearly specified and maintained**. For example, if network utilization is an area of concern, the architect should produce (and enforce) for each development team guidelines that will result in a minimum of network traffic. If performance is a concern, the architect should produce (and enforce) time budgets for the major threads.
