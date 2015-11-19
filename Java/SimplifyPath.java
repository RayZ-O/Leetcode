// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

public class SimplifyPath {
    public String simplifyPath(String path) {
        String[] parts = path.split("/");
        LinkedList<String> list = new LinkedList<>();
        for (String s : parts) {
            if (s.equals(".") || s.isEmpty()) {
                continue;
            } else if (s.equals("..")) {
                if (!list.isEmpty())
                    list.removeLast();
            } else {
                list.addLast(s);
            }
        }
        StringBuilder builder = new StringBuilder();
        for (String s : list) {
            builder.append("/" + s);
        }
        return builder.length() == 0? "/" : builder.toString();
    }
}
