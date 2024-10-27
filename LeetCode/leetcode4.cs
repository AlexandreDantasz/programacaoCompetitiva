public class Solution {
        private static Random rand = new Random();

        private static int Partition(int[] array, int begin, int end)
        {
                int indexPivot = rand.Next(begin, end + 1);
                int pivot = array[indexPivot], i = begin;
                (array[indexPivot], array[end]) = (array[end], array[indexPivot]);
                for (int j = begin; j < end; j++)
                {
                        if (pivot <= array[j])
                        {
                                (array[i], array[j]) = (array[j], array[i]);
                                i++;
                        }
                }

                (array[end], array[i]) = (array[i], array[end]);
                return i;
        }

        private static void Quicksort(int[] array, int begin, int end)
        {
                if (begin < end)
                {
                        int middle = Partition(array, begin, end);
                        Quicksort(array, begin, middle - 1);
                        Quicksort(array, middle + 1, end);
                }
        }

        public double FindMedianSortedArrays(int[] nums1, int[] nums2) {

                int[] arraySum = new int[nums1.Length + nums2.Length];
                for (int i = 0; i < nums1.Length; i++)
                        arraySum[i] = nums1[i];

                int lastIndex = nums1.Length;
                for (int i = 0; i < nums2.Length; i++)
                        arraySum[lastIndex++] = nums2[i];

                Quicksort(arraySum, 0, arraySum.Length - 1);

                if (arraySum.Length % 2 == 1)
                {
                        int position = arraySum.Length / 2;
                        return arraySum[position];
                }
                else
                {
                        int position = arraySum.Length / 2;
                        return (arraySum[position] + arraySum[position - 1]) / 2.0;
                }
        }
}
