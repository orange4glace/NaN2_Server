for FILE in $1
do
  $2 -MM -MT $3/$FILE.o $FILE.cpp $4 >> $5;
done


# @for FILE in $(LIB_SRCS:%.c=%) $(TARGET_SRCS:%.c=%); do \
#   $(CC) -MM -MT $(OBJS_DIR)/$$FILE.o $$FILE.c \
#     $(CFLAGS) $(DBG_FLAGS) $(INC_DIRS) >> $(DEPEND_FILE); \
# done
