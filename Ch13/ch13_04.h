#ifndef CH1304H
#define CH1304H

#include <set>
#include <string>

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

 public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();

  // 从给定Folder添加/删除本Message
  void save(Folder &);
  void remove(Folder &);

  const std::string getContents() const { return contents; }

 private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

class Folder {
 public:
  Folder(/* args */) = default;

  void addMsg(Message *);
  void remMsg(Message *);

 private:
  std::set<Message *> messages;
};

#endif