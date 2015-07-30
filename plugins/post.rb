module Jekyll
  class Post
    def populate_categories
      categories_from_data = Utils.pluralized_array_from_hash(data, 'category', 'categories')
      self.categories = (
        Array(categories) + categories_from_data
      ).flatten.uniq
    end
  end
end
