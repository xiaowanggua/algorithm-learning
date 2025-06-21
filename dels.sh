#!/bin/bash

# 此脚本用于删除没有文件后缀名的文件。
# 它会特意忽略 .git 目录及其中的任何文件。

# 默认将目标目录设置为当前目录。
# 你也可以将一个目录作为参数传递给脚本，例如：./cleanup.sh /path/to/your/folder
TARGET_DIR="${1:-.}"

echo "将在以下目录中搜索无后缀名的文件: $TARGET_DIR"
echo "--------------------------------------------------"
# 使用 find 命令查找文件
# -path "$TARGET_DIR/.git" -prune: 从搜索中排除 .git 目录。
# -o: OR 操作符，用于组合条件。
# -type f: 只查找普通文件（不包括目录、链接等）。
# -not -name "*.*": 查找文件名中不包含"."的文件。这能有效找出无后缀文件，
#                   同时也会自动忽略以"."开头的隐藏文件（如 .gitignore），因为它们匹配 "*.*"。
FILES_TO_DELETE=$(find "$TARGET_DIR" -path "$TARGET_DIR/.git" -prune -o -type f -not -name "*.*" -print)

if [ -z "$FILES_TO_DELETE" ]; then
    echo "未找到无后缀名的文件。"
    exit 0
fi

echo "以下文件将被删除:"
echo "$FILES_TO_DELETE"
echo "--------------------------------------------------"

read -p "您确定要删除以上列出的所有文件吗？ (y/N) " confirm

# 检查用户的输入是否为 y 或 Y
if [[ "$confirm" =~ ^[yY]$ ]]; then
    # 如果确认，则再次运行 find 命令并使用 -delete 操作。
    # 使用 xargs 和 rm 可以提供更好的兼容性
    echo "$FILES_TO_DELETE" | xargs rm
    echo "删除完成。"
else
    echo "操作已取消。"
fi