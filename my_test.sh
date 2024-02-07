#!/bin/bash

# Задайте аргументы для тестирования
ARG="5 9 8"

# Запустите push_swap с аргументами и подсчитайте количество инструкций
echo "Запускаем push_swap с аргументами: $ARG"
INSTRUCTIONS=$(./push_swap $ARG)
COUNT=$(echo "$INSTRUCTIONS" | wc -l)

echo "Количество инструкций: $COUNT"
echo

# Проверьте корректность сортировки с помощью checker_OS
echo "Проверка результатов сортировки с помощью checker_OS:"
RESULT=$(echo "$INSTRUCTIONS" | ./checker_linux $ARG)

if [ "$RESULT" = "OK" ]; then
  echo "Результат проверки: OK - сортировка выполнена корректно"
else
  echo "Результат проверки: KO - сортировка выполнена некорректно"
fi
