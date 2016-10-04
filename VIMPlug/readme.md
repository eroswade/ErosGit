vim 插件说明
======================
# 安装
在VIM安装路径下. 修改vimrc 增加
set rtp+=E:\Develop\VimPlug\vimfiles
source E:\Develop\VimPlug\_vimrc
把bundle解压缩到VIM安装路径\VIMFILES\bundle里. 因为bundle里的东西无法安装在别的路径里

#已用插件:

## bufexplorer-7.4.6
查看当前已经打开的文件 命令:<lead>be
## ctags
生成TAG文件
## nerdcommenter
注释代码工具
- ,ca，在可选的注释方式之间切换，比如C/C++ 的块注释/* */和行注释//
- ,cc，注释当前行
- ,c，切换注释/非注释状态
- ,cs，以”性感”的方式注释
- ,cA，在当前行尾添加注释符，并进入Insert模式
- ,cu，取消注释
## nerdtree
和fileexplorer一样,都是用来打开文件的   
## omnicppcomplete-0.41
自动补全工具
## supertab
和omni一起用,用TAB代替C+X C+O 
1. Whole lines						|i_CTRL-X_CTRL-L|
2. keywords in the current file				|i_CTRL-X_CTRL-N|
3. keywords in 'dictionary'				|i_CTRL-X_CTRL-K|
4. keywords in 'thesaurus', thesaurus-style		|i_CTRL-X_CTRL-T|
5. keywords in the current and included files		|i_CTRL-X_CTRL-I|
6. tags							|i_CTRL-X_CTRL-]|
7. file names						|i_CTRL-X_CTRL-F|
8. definitions or macros				|i_CTRL-X_CTRL-D|
9. Vim command-line					|i_CTRL-X_CTRL-V|
10. User defined completion				|i_CTRL-X_CTRL-U|
11. omni completion					|i_CTRL-X_CTRL-O|
12. Spelling suggestions				|i_CTRL-X_s|
13. keywords in 'complete'				|i_CTRL-N|

## tabular.tar
在VIM中对齐文本  执行方式: :tab/?  ?为要对齐的内容,以?对齐,可以是空格,等号,|号,逗号等
## taglist_46
tag list view
## vim-indent-guides-master 
用来做分层提示.
## winmanager
WIM MANAGER 在VIMRC里用来管理TAGLIST和FILEEXPLORER
## snipmate 
和VA一样的功能,写一些,然后自动扩展可支持很多种文件
## bundle.rar
    这个是增加的内容,把之前的supertab和snipmate打包.放到VIM的安装目录下.这两个包在这个目录下无法正常工作
## FencAutoDectect
    这个是检测编码的库
    首先输入:FencAutoDectect自动检测,然后就可以:FencView查看自动检测到的字符集是什么了.
:F然后直接tab按键就可以了,不用全部输入
:FencAutoDectect
:FencView
重复输入:FencView世视窗在'关闭/打开'之间切换
## vimwiki
    增加VIMWIKI支持
    Basic Markup
    see `:h vimwiki-syntax`
    Key bindings
    see `:h vimwiki-mappings`
    Commands 
    * `:Vimwiki2HTML` -- Convert current wiki link to HTML 
    * `:VimwikiAll2HTML` -- Convert all your wiki links to HTML 
    * `:help vimwiki-commands` -- list all commands
